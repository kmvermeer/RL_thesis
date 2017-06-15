/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eom.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "eom.h"
#include "simulateDNA_emxutil.h"
#include "computeQdd.h"
#include "newton_raphson.h"

/* Function Definitions */

/*
 * Arguments    : double t
 *                emxArray_real_T *x0
 *                double nx0
 *                const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                const emxArray_real_T *DNA_Mpar
 *                const emxArray_real_T *DNA_Hpar
 *                const emxArray_real_T *DNA_Spar
 *                const emxArray_real_T *DNA_Ppar
 *                const emxArray_real_T *DNA_Pmpar
 *                emxArray_real_T *qss
 * Return Type  : void
 */
void eom(double t, emxArray_real_T *x0, double nx0, const emxArray_real_T
         *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
         emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
         emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
         emxArray_real_T *DNA_Pmpar, emxArray_real_T *qss)
{
  double d0;
  int i6;
  newton_raphson(t, x0, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
                 DNA_Spar, DNA_Ppar, DNA_Pmpar);
  computeQdd(t, x0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
             DNA_Ppar, DNA_Pmpar, qss);
  d0 = nx0 * 2.0;
  i6 = qss->size[0];
  if (1.0 > d0) {
    qss->size[0] = 0;
  } else {
    qss->size[0] = (int)d0;
  }

  emxEnsureCapacity((emxArray__common *)qss, i6, (int)sizeof(double));
}

/*
 * File trailer for eom.c
 *
 * [EOF]
 */
