/* Stabilize.cpp - Stabilize Library
 *
 */

#include "Stabilize.h"
#include "Arduino.h"

/* Stabilize
 *
 * Description
 *   Stabilize.
 *
 *   Stabilize ()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
Stabilize::Stabilize(int samples, float threshold) {
  begin(samples, threshold);
}

/* begin
 *
 * Description
 *   Define initial parameters.
 *
 *   variable.begin(int samples)
 *
 * Parameters
 *   samples: Stabilization samples
 *   threshold: Stabilization threshold
 *
 * Returns
 *   void
 */
void Stabilize::begin(int samples, float threshold) {
  _samples = samples;
  _threshold = threshold;
  _samples_counter = 0;
  _result = 0;
}

/* sample
 *
 * Description
 *   Update user input value.
 *
 *   variable.sample(float value)
 *
 * Parameters
 *   value: user input value
 *
 * Returns
 *   float: Stabilized value
 */
float Stabilize::sample(float value) {
  if (_samples_counter == _samples) {
    _result = value;
    _samples_counter = 0;
  }
  _samples_counter++;

  if (abs(value - _result) >= _threshold) {
    _result = value;
  }

  return _result;
}
