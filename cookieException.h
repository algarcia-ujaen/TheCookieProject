/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cookieException.h
 * Author: algarcia
 *
 * Created on 23 de abril de 2020, 12:09
 */

#ifndef COOKIEEXCEPTION_H
#define COOKIEEXCEPTION_H

#include <stdexcept>


class cookieException: public std::logic_error
{
   public:
      cookieException ( std::string mensaje );
      cookieException ( const cookieException& orig );
      virtual ~cookieException ( ) noexcept;
} ;

#endif /* COOKIEEXCEPTION_H */

