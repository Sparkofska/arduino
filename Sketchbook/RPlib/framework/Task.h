#ifndef TASK_H
#define TASK_H

class Task
{
private:
	const byte _id;

protected:
  virtual void work(unsigned long now) = 0; // must be unsigned to avoid computation errors. Please take care of it in all Tasks

public:
  Task(byte id):_id(id) { };

  virtual void run(long currentTime) =0;

  virtual void activate() =0;

  virtual void deactivate() =0;

  virtual bool getActive() =0;
  
  int getId(){return _id;}
};

#endif //TASK_H
