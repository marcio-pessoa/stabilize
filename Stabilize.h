/* Stabilize.h - Stabilize Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 *
 * Change log:
 * 2023-02-26
 *   Add begin into constructor.
 *
 * 2023-01-15
 *   Experimental version.
 */

#ifndef Stabilize_h
#define Stabilize_h

#include "Arduino.h"

class Stabilize {
 public:
  Stabilize(int samples = 10, float threshold = 0.3);
  void begin(int samples, float threshold);
  float sample(float value);

 private:
  float _result;
  int _samples;
  int _samples_counter;
  float _threshold;
};

#endif
