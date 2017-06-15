/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "mean.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                double y[2]
 * Return Type  : void
 */
void mean(const emxArray_real_T *x, double y[2])
{
  int vlen;
  int i;
  int xoffset;
  double s;
  int k;
  if (x->size[0] == 0) {
    for (vlen = 0; vlen < 2; vlen++) {
      y[vlen] = 0.0;
    }
  } else {
    vlen = x->size[0];
    for (i = 0; i < 2; i++) {
      xoffset = i * vlen;
      s = x->data[xoffset];
      for (k = 2; k <= vlen; k++) {
        s += x->data[(xoffset + k) - 1];
      }

      y[i] = s;
    }
  }

  i = x->size[0];
  for (vlen = 0; vlen < 2; vlen++) {
    y[vlen] /= (double)i;
  }
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
