#ifndef __MYTIME_H
#define __MYTIME_H

class MyTime {
  int m_hours;
  int m_minutes;
  int m_seconds;
  public:
  MyTime();
  MyTime(int,int,int);
  MyTime(int,int);
  MyTime operator+(const MyTime&);
  MyTime operator-(const MyTime&);
  MyTime operator+(int);
  MyTime operator-(int);
  MyTime& operator++();
  MyTime operator++(int);
  MyTime& operator+=(const MyTime&);
  bool operator==(const MyTime&);
  int gethr();
  int getmin();
  int getsec();
  void dispay() const;
  
};

#endif
