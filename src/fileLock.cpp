/**
 * 
 * @file fileLock.cpp
 * 
 * @brief Implementation of fileLock class.
 * 
 * @author Adam Novak (annmproject@protonmail.com)
 * @copyright Copyright (c) 2021 Adam Novak. Details about license and more 
 *            you can find here: https://github.com/annmproject/fileLock.
 * 
 */

#include <fileLock/fileLock.hpp>


namespace annm {

    /*
     *
     * Constructor
     * 
     */

    fileLock::fileLock(std::string &filename, std::string &mode) {
        this->filename = filename;
        this->mode     = mode;
        this->isLocked = false;
    }


    /*
     *
     * Destructor
     * 
     */

    fileLock::~fileLock() {
        if(this->isLocked) {
            fflush(this->file);
            fsync(fileno(this->file));
            flock(fileno(this->file), LOCK_UN);
            fclose(this->file);
        }
    }


    /*
     *
     * Lock
     * 
     */

    bool fileLock::lock() {
        
        if(this->isLocked) {
            return true;
        }

        if((this->file = fopen(this->filename.c_str(), this->mode.c_str())) == NULL) {
            return false;
        }

        flock(fileno(this->file), LOCK_EX);

        this->isLocked = true;

        return true;

    }


    /*
     *
     * Pointer
     * 
     */

    FILE *fileLock::pointer() {
        return this->file;
    }


    /*
     *
     * Unlock
     * 
     */

    void fileLock::unlock() {
        if(this->isLocked) {
            fflush(this->file);
            fsync(fileno(this->file));
            flock(fileno(this->file), LOCK_UN);
            fclose(this->file);
            this->file     = NULL;
            this->isLocked = false;
        }
    }


}
