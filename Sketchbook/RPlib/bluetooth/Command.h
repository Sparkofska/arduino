#ifndef COMMAND_H
#define COMMAND_H

class Command
{
private:
	byte _tag;

protected:
	virtual byte* getFields(byte &length) = 0;

public:
  Command(byte tag):_tag(tag) { };

const static char CMD_END =';';
  
  byte getTag(){return _tag;}
  void setTag(byte tag){_tag = tag;}

  byte* getBytes(byte &length){
  	byte l =0;
  	byte* fields = getFields(l);
  	length = l+2;
  	byte bytes[length];
  	bytes[0] = _tag;
  	bytes[length-1] = CMD_END;
  	return bytes;
  }
};

#endif //COMMAND_H