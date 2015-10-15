#ifndef TYPESIZEPRINTER_H
#define TYPESIZEPRINTER_H

#include "../framework/Once.h"

class TypeSizePrinter : public Once
{

private:

protected:
  void work(long now)
  {
    Serial.println("");
    Serial.println("Size of primitive Types in byte:");
    Serial.println("================================");

   Serial.print("Size of bool : ");
   Serial.println(sizeof(bool));
	
   Serial.print("Size of char : ");
   Serial.println(sizeof(char));

   Serial.print("Size of byte : ");
   Serial.println(sizeof(byte));

   Serial.print("Size of int : ");
   Serial.println(sizeof(int));

   Serial.print("Size of short int : ");
   Serial.println(sizeof(short int));

   Serial.print("Size of long int : ");
   Serial.println(sizeof(long int));

   Serial.print("Size of float : ");
   Serial.println(sizeof(float));

   Serial.print("Size of double : ");
   Serial.println(sizeof(double));

   Serial.print("Size of wchar_t : ");
   Serial.println(sizeof(wchar_t));

  Serial.println("================================");
  Serial.println("");

  }

public:
  /**
  * 
  */
  TypeSizePrinter(byte id, bool active)
    : Once(id, active)
    {
      Serial.begin(9600);
    };

};


#endif //TYPESIZEPRINTER_H