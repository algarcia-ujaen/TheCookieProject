/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   cookieException.cpp
 * Author: algarcia
 *
 * Created on 23 de abril de 2020, 12:09
 */

#include "cookieException.h"

cookieException::cookieException ( std::string mensaje ):
                                 std::logic_error ( mensaje )
{ }

cookieException::cookieException ( const cookieException& orig ):
                                 std::logic_error ( orig )
{ }

cookieException::~cookieException ( )
{ }

