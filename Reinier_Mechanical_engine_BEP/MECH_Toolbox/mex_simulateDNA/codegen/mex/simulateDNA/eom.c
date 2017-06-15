/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eom.c
 *
 * Code generation for function 'eom'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "eom.h"
#include "simulateDNA_emxutil.h"
#include "indexShapeCheck.h"
#include "computeQdd.h"
#include "newton_raphson.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 6, "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m"
};

static emlrtRSInfo hc_emlrtRSI = { 8, "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m"
};

static emlrtRSInfo ic_emlrtRSI = { 10, "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 10, 1, "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m"
};

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 10, 7, "qss", "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 10, 7, "eom",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\eom.m",
  1 };

/* Function Definitions */
void eom(const emlrtStack *sp, real_T t, emxArray_real_T *x0, real_T nx0, const
         emxArray_real_T *DNA_incstr, const emxArray_real_T *DNA_edgelabel,
         const emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
         emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
         emxArray_real_T *DNA_Pmpar, emxArray_real_T *qss)
{
  real_T d0;
  int32_T i9;
  int32_T i10;
  int32_T iv9[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gc_emlrtRSI;
  newton_raphson(&st, t, x0, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
                 DNA_Spar, DNA_Ppar, DNA_Pmpar);
  st.site = &hc_emlrtRSI;
  computeQdd(&st, t, x0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
             DNA_Ppar, DNA_Pmpar, qss);
  d0 = nx0 * 2.0;
  if (1.0 > d0) {
    i10 = 0;
  } else {
    i9 = qss->size[0];
    if (!(1 <= i9)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i9, &pc_emlrtBCI, sp);
    }

    if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
      emlrtIntegerCheckR2012b(d0, &e_emlrtDCI, sp);
    }

    i9 = qss->size[0];
    i10 = (int32_T)d0;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &pc_emlrtBCI, sp);
    }
  }

  iv9[0] = 1;
  iv9[1] = i10;
  st.site = &ic_emlrtRSI;
  indexShapeCheck(&st, qss->size[0], iv9);
  i9 = qss->size[0];
  qss->size[0] = i10;
  emxEnsureCapacity(sp, (emxArray__common *)qss, i9, (int32_T)sizeof(real_T),
                    &y_emlrtRTEI);
}

/* End of code generation (eom.c) */
