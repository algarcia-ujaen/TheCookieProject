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


class CookieException: public std::logic_error
{
   public:
      CookieException ( std::string mensaje );
      CookieException ( const CookieException& orig );
      virtual ~CookieException ( ) noexcept;
} ;

#endif /* COOKIEEXCEPTION_H */

