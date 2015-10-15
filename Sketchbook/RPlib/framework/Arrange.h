#ifndef ARRANGE_H
#define ARRANGE_H

#include <list>
#include "Arduino.h"

class Task;

/*
Verwendung 
==========
Arrange::getInstance ()->xyz ();
*/

class Arrange
{  
public:
  static Arrange* getInstance ()
  {
    // keine Speicherbereinigung. Aber Arrange soll/kann über gesamten Zeitraum bestehen bleiben
    if (!_instance)
      _instance = new Arrange;
    return _instance;
  }


virtual void spin();

virtual inline void registerTask(Task *task);

virtual inline void unregisterTask(Task *task);

void printOngoingTasks();


private:
static Arrange* _instance;

Arrange () { } // verhindert, dass ein Objekt von außerhalb von N erzeugt wird. // protected, wenn man von der Klasse noch erben möchte
~Arrange () { }

Arrange ( const Arrange& ); // verhindert, dass eine weitere Instanz via Kopie-Konstruktor erstellt werden kann

std::list<Task*> _ongoingTasks;


};
Arrange* Arrange::_instance = 0; // statische Elemente einer Klasse müssen initialisiert werden. 


#endif //ARRANGE_H