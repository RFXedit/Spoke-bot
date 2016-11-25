/*
||
|| @file Clavier4x4.cpp
|| @version 1
|| @author Jonathan Courbon
|| @contact jonathan.courbon@udamail.fr
||
|| @description
|| | Cette librairie fournit une interface simple pour utiliser le clavier souple 4x4 touches (avec autocollants)
|| | La librairie Keypad ne fonctionnait pas (touches d'une ligne non reconnues)
||
|| @license
|| | This library is free software; you can redistribute it and/or
|| | modify it under the terms of the GNU Lesser General Public
|| | License as published by the Free Software Foundation; version
|| | 2.1 of the License.
|| |
|| | This library is distributed in the hope that it will be useful,
|| | but WITHOUT ANY WARRANTY; without even the implied warranty of
|| | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| | Lesser General Public License for more details.
|| |
|| | You should have received a copy of the GNU Lesser General Public
|| | License along with this library; if not, write to the Free Software
|| | Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
|| #
||
*/
// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Clavier4x4.h"

// <<constructor>> 

Clavier4x4::Clavier4x4(int row1,int row2,int row3,int row4,int col1,int col2,int col3,int col4)
{
	row[0]=row1;row[1]=row2;row[2]=row3;row[3]=row4;
	col[0]=col1;col[1]=col2;col[2]=col3;col[3]=col4;

	touches[0][0] = '1';	touches[0][1] = '2';	touches[0][2] = '3';	touches[0][3] = 'A';
	touches[1][0] = '4';	touches[1][1] = '5';	touches[1][2] = '6';	touches[1][3] = 'B';
	touches[2][0] = '7';	touches[2][1] = '8';	touches[2][2] = '9';	touches[2][3] = 'C';
	touches[3][0] = '*';	touches[3][1] = '0';	touches[3][2] = '#';	touches[3][3] = 'D';
}

void Clavier4x4::init()
{
	for(int i=0;i<4;i++)
	{
		pinMode(row[i],OUTPUT); 
		pinMode(col[i],INPUT_PULLUP);
		digitalWrite(row[i],HIGH);
	}
}

char Clavier4x4::getKey()
{
	char key=NO_KEY;
	for (int i=0;i<4;i++)  {
    		digitalWrite(row[i],LOW);
		for (int j=0;j<4;j++)  {
			if (digitalRead(col[j]) == LOW) {
				key=touches[i][j];
			}
		}
		digitalWrite(row[i],HIGH);
	}
	return key;
}

/*
|| @changelog

|| #
*/
