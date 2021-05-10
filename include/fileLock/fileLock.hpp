/**
 * 
 * @file fileLock.hpp
 * 
 * @brief Header of fileLock class.
 * 
 * @author Adam Novak (annmproject@protonmail.com)
 * @copyright Copyright (c) 2021 Adam Novak. Details about license and more 
 *            you can find here: https://github.com/annmproject/fileLock.
 * 
 */

#ifndef ANNM_FILE_LOCK_HPP
#define ANNM_FILE_LOCK_HPP

#include <iostream>
#include <string>
#include <sys/file.h>
#include <unistd.h>

using namespace std;

namespace annm {

    class fileLock {
        
        private:
            std::string  filename;
            std::string  mode;
            std::FILE   *file;
            bool         isLocked;


        public:

            /**
             * 
             * @brief Constructor initializes class variables.
             * 
             * @param filename Name of the file what will be locked.
             * @param mode     Mode in what will be the file opened.
             * 
             */

            fileLock(std::string &filename, std::string &mode);
            

            /**
             * 
             * @brief Destructor checks if file is unlocked and closed. If not It will do it.
             * 
             */

            ~fileLock();


            /**
             * 
             * @brief The method opens the file and waits until it is unlocked, then locks it. 
             * 
             * @return True if file was successfully locked, otherwise false.
             * 
             */

            bool lock();


            /**
             * 
             * @brief Method returns pointer to file.
             * 
             * @return Pointer to file.
             * 
             */
            
            FILE *pointer();


            /**
             * 
             * @brief Method unlocks the file and closes it.
             * 
             */

            void unlock();


    };

}


#endif