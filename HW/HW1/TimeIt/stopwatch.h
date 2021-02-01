#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::time_point;
using std::ctime;
using std::time_t;

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

class StopWatch {
private:

  time_point<system_clock> _start;
  time_point<system_clock> _end;

  duration<double> _elapsedSeconds;
  duration<double, std::milli> _elapsedMillis;

public:

  StopWatch() {
    _start = system_clock::now();
  }

  void stop() {
    _end = system_clock::now();

    _elapsedSeconds  = _end - _start;
    _elapsedMillis = _end - _start;
  }

  void start() {
    _start = system_clock::now();
  }

  double getElapsedSeconds() {
    return _elapsedSeconds.count();
  }

  double getElapsedMillis() {
    return _elapsedMillis.count();
  }

};


#endif
