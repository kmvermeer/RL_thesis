/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: DNA2inc.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "DNA2inc.h"
#include "simulateDNA_emxutil.h"
#include "str2inc.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                emxArray_real_T *inc
 * Return Type  : void
 */
void DNA2inc(const emxArray_real_T *DNA_incstr, emxArray_real_T *inc)
{
  emxArray_real_T *edgelist;
  int n;
  int ix;
  unsigned int sedgelist[2];
  int k;
  emxArray_real_T *maxval;
  boolean_T x_data[100];
  int ii_data[100];
  int b_ix;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int mtmp;
  int b_ii_data[100];

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Function */
  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Switch */
  emxInit_real_T(&edgelist, 2);
  if (!(DNA_incstr->size[1] == 0)) {
    str2inc(DNA_incstr, inc);
    n = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = DNA_incstr->size[1];
    emxEnsureCapacity((emxArray__common *)edgelist, n, (int)sizeof(double));
    ix = DNA_incstr->size[1] << 1;
    for (n = 0; n < ix; n++) {
      edgelist->data[n] = 0.0;
    }

    for (k = 0; k < inc->size[1]; k++) {
      ix = inc->size[0];
      for (n = 0; n < ix; n++) {
        x_data[n] = (inc->data[n + inc->size[0] * k] == 1.0);
      }

      n = 0;
      b_ix = 1;
      exitg1 = false;
      while ((!exitg1) && (b_ix <= ix)) {
        guard1 = false;
        if (x_data[b_ix - 1]) {
          n++;
          ii_data[n - 1] = b_ix;
          if (n >= ix) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          b_ix++;
        }
      }

      if (ix == 1) {
        if (n == 0) {
          ix = 0;
        }
      } else if (1 > n) {
        ix = 0;
      } else {
        ix = n;
      }

      for (n = 0; n < ix; n++) {
        b_ii_data[n] = ii_data[n];
      }

      for (n = 0; n < 2; n++) {
        edgelist->data[n + edgelist->size[0] * k] = b_ii_data[n];
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    n = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)edgelist, n, (int)sizeof(double));
  }

  /* Functioin */
  /* Function */
  for (n = 0; n < 2; n++) {
    sedgelist[n] = (unsigned int)edgelist->size[n];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(&maxval, 2);
    n = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = edgelist->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, n, (int)sizeof(double));
    for (n = 0; n + 1 <= edgelist->size[1]; n++) {
      ix = n << 1;
      b_ix = (n << 1) + 1;
      mtmp = (int)edgelist->data[ix];
      if (b_ix < ix + 2) {
        while (b_ix + 1 <= ix + 2) {
          if ((int)edgelist->data[b_ix] > mtmp) {
            mtmp = (int)edgelist->data[b_ix];
          }

          b_ix++;
        }
      }

      maxval->data[n] = mtmp;
    }

    n = maxval->size[1];
    mtmp = (int)maxval->data[0];
    if (maxval->size[1] > 1) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int)maxval->data[ix] > mtmp) {
          mtmp = (int)maxval->data[ix];
        }
      }
    }

    emxFree_real_T(&maxval);
    n = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int)sedgelist[1];
    emxEnsureCapacity((emxArray__common *)inc, n, (int)sizeof(double));
    ix = mtmp * (int)sedgelist[1];
    for (n = 0; n < ix; n++) {
      inc->data[n] = 0.0;
    }

    for (k = 0; k < (int)sedgelist[1]; k++) {
      for (n = 0; n < 2; n++) {
        inc->data[((int)edgelist->data[n + edgelist->size[0] * k] + inc->size[0]
                   * k) - 1] = 1.0;
      }
    }

    /* For */
  } else {
    n = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)inc, n, (int)sizeof(double));
  }

  emxFree_real_T(&edgelist);

  /* If */
}

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                emxArray_real_T *inc
 * Return Type  : void
 */
void b_DNA2inc(const emxArray_real_T *DNA_incstr, const emxArray_real_T
               *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r7;
  int i;
  int mtmp;
  emxArray_int32_T *indx;
  int ix;
  int n;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  unsigned int sedgelist[2];
  emxArray_real_T *maxval;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int b_ii_data[100];
  emxInit_boolean_T(&r7, 2);

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Function */
  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = r7->size[0] * r7->size[1];
  r7->size[0] = 1;
  r7->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)r7, i, (int)sizeof(boolean_T));
  mtmp = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i = 0; i < mtmp; i++) {
    r7->data[i] = (DNA_edgelabel->data[i] == 1.0);
  }

  emxInit_int32_T1(&indx, 2);
  ix = r7->size[1] - 1;
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r7->data[i]) {
      n++;
    }
  }

  i = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = n;
  emxEnsureCapacity((emxArray__common *)indx, i, (int)sizeof(int));
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r7->data[i]) {
      indx->data[n] = i + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r7);

  /* Switch */
  emxInit_real_T(&edgelist, 2);
  if (!(indx->size[1] == 0)) {
    emxInit_real_T(&b_DNA_incstr, 2);
    i = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = indx->size[1];
    emxEnsureCapacity((emxArray__common *)b_DNA_incstr, i, (int)sizeof(double));
    mtmp = indx->size[0] * indx->size[1];
    for (i = 0; i < mtmp; i++) {
      b_DNA_incstr->data[i] = DNA_incstr->data[indx->data[i] - 1];
    }

    str2inc(b_DNA_incstr, inc);
    n = indx->size[1];
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
    mtmp = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i = 0; i < mtmp; i++) {
      edgelist->data[i] = 0.0;
    }

    for (k = 0; k < inc->size[1]; k++) {
      mtmp = inc->size[0];
      for (i = 0; i < mtmp; i++) {
        x_data[i] = (inc->data[i + inc->size[0] * k] == 1.0);
      }

      n = 0;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= mtmp)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= mtmp) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (mtmp == 1) {
        if (n == 0) {
          mtmp = 0;
        }
      } else if (1 > n) {
        mtmp = 0;
      } else {
        mtmp = n;
      }

      for (i = 0; i < mtmp; i++) {
        b_ii_data[i] = ii_data[i];
      }

      for (i = 0; i < 2; i++) {
        edgelist->data[i + edgelist->size[0] * k] = b_ii_data[i];
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
  }

  emxFree_int32_T(&indx);

  /* Functioin */
  /* Function */
  for (i = 0; i < 2; i++) {
    sedgelist[i] = (unsigned int)edgelist->size[i];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(&maxval, 2);
    i = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = edgelist->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, i, (int)sizeof(double));
    for (i = 0; i + 1 <= edgelist->size[1]; i++) {
      ix = i << 1;
      n = (i << 1) + 1;
      mtmp = (int)edgelist->data[ix];
      if (n < ix + 2) {
        while (n + 1 <= ix + 2) {
          if ((int)edgelist->data[n] > mtmp) {
            mtmp = (int)edgelist->data[n];
          }

          n++;
        }
      }

      maxval->data[i] = mtmp;
    }

    n = maxval->size[1];
    mtmp = (int)maxval->data[0];
    if (maxval->size[1] > 1) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int)maxval->data[ix] > mtmp) {
          mtmp = (int)maxval->data[ix];
        }
      }
    }

    emxFree_real_T(&maxval);
    i = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int)sedgelist[1];
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
    mtmp *= (int)sedgelist[1];
    for (i = 0; i < mtmp; i++) {
      inc->data[i] = 0.0;
    }

    for (k = 0; k < (int)sedgelist[1]; k++) {
      for (i = 0; i < 2; i++) {
        inc->data[((int)edgelist->data[i + edgelist->size[0] * k] + inc->size[0]
                   * k) - 1] = 1.0;
      }
    }

    /* For */
  } else {
    i = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
  }

  emxFree_real_T(&edgelist);

  /* If */
}

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                emxArray_real_T *inc
 * Return Type  : void
 */
void c_DNA2inc(const emxArray_real_T *DNA_incstr, const emxArray_real_T
               *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r8;
  int i;
  int mtmp;
  emxArray_int32_T *indx;
  int ix;
  int n;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  unsigned int sedgelist[2];
  emxArray_real_T *maxval;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int b_ii_data[100];
  emxInit_boolean_T(&r8, 2);

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Function */
  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = r8->size[0] * r8->size[1];
  r8->size[0] = 1;
  r8->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)r8, i, (int)sizeof(boolean_T));
  mtmp = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i = 0; i < mtmp; i++) {
    r8->data[i] = (DNA_edgelabel->data[i] == 3.0);
  }

  emxInit_int32_T1(&indx, 2);
  ix = r8->size[1] - 1;
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r8->data[i]) {
      n++;
    }
  }

  i = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = n;
  emxEnsureCapacity((emxArray__common *)indx, i, (int)sizeof(int));
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r8->data[i]) {
      indx->data[n] = i + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r8);

  /* Switch */
  emxInit_real_T(&edgelist, 2);
  if (!(indx->size[1] == 0)) {
    emxInit_real_T(&b_DNA_incstr, 2);
    i = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = indx->size[1];
    emxEnsureCapacity((emxArray__common *)b_DNA_incstr, i, (int)sizeof(double));
    mtmp = indx->size[0] * indx->size[1];
    for (i = 0; i < mtmp; i++) {
      b_DNA_incstr->data[i] = DNA_incstr->data[indx->data[i] - 1];
    }

    str2inc(b_DNA_incstr, inc);
    n = indx->size[1];
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
    mtmp = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i = 0; i < mtmp; i++) {
      edgelist->data[i] = 0.0;
    }

    for (k = 0; k < inc->size[1]; k++) {
      mtmp = inc->size[0];
      for (i = 0; i < mtmp; i++) {
        x_data[i] = (inc->data[i + inc->size[0] * k] == 1.0);
      }

      n = 0;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= mtmp)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= mtmp) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (mtmp == 1) {
        if (n == 0) {
          mtmp = 0;
        }
      } else if (1 > n) {
        mtmp = 0;
      } else {
        mtmp = n;
      }

      for (i = 0; i < mtmp; i++) {
        b_ii_data[i] = ii_data[i];
      }

      for (i = 0; i < 2; i++) {
        edgelist->data[i + edgelist->size[0] * k] = b_ii_data[i];
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
  }

  emxFree_int32_T(&indx);

  /* Functioin */
  /* Function */
  for (i = 0; i < 2; i++) {
    sedgelist[i] = (unsigned int)edgelist->size[i];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(&maxval, 2);
    i = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = edgelist->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, i, (int)sizeof(double));
    for (i = 0; i + 1 <= edgelist->size[1]; i++) {
      ix = i << 1;
      n = (i << 1) + 1;
      mtmp = (int)edgelist->data[ix];
      if (n < ix + 2) {
        while (n + 1 <= ix + 2) {
          if ((int)edgelist->data[n] > mtmp) {
            mtmp = (int)edgelist->data[n];
          }

          n++;
        }
      }

      maxval->data[i] = mtmp;
    }

    n = maxval->size[1];
    mtmp = (int)maxval->data[0];
    if (maxval->size[1] > 1) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int)maxval->data[ix] > mtmp) {
          mtmp = (int)maxval->data[ix];
        }
      }
    }

    emxFree_real_T(&maxval);
    i = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int)sedgelist[1];
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
    mtmp *= (int)sedgelist[1];
    for (i = 0; i < mtmp; i++) {
      inc->data[i] = 0.0;
    }

    for (k = 0; k < (int)sedgelist[1]; k++) {
      for (i = 0; i < 2; i++) {
        inc->data[((int)edgelist->data[i + edgelist->size[0] * k] + inc->size[0]
                   * k) - 1] = 1.0;
      }
    }

    /* For */
  } else {
    i = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
  }

  emxFree_real_T(&edgelist);

  /* If */
}

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                emxArray_real_T *inc
 * Return Type  : void
 */
void d_DNA2inc(const emxArray_real_T *DNA_incstr, const emxArray_real_T
               *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r9;
  int i;
  int mtmp;
  emxArray_int32_T *indx;
  int ix;
  int n;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  unsigned int sedgelist[2];
  emxArray_real_T *maxval;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int b_ii_data[100];
  emxInit_boolean_T(&r9, 2);

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Function */
  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = r9->size[0] * r9->size[1];
  r9->size[0] = 1;
  r9->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)r9, i, (int)sizeof(boolean_T));
  mtmp = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i = 0; i < mtmp; i++) {
    r9->data[i] = (DNA_edgelabel->data[i] == 4.0);
  }

  emxInit_int32_T1(&indx, 2);
  ix = r9->size[1] - 1;
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r9->data[i]) {
      n++;
    }
  }

  i = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = n;
  emxEnsureCapacity((emxArray__common *)indx, i, (int)sizeof(int));
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r9->data[i]) {
      indx->data[n] = i + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r9);

  /* Switch */
  emxInit_real_T(&edgelist, 2);
  if (!(indx->size[1] == 0)) {
    emxInit_real_T(&b_DNA_incstr, 2);
    i = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = indx->size[1];
    emxEnsureCapacity((emxArray__common *)b_DNA_incstr, i, (int)sizeof(double));
    mtmp = indx->size[0] * indx->size[1];
    for (i = 0; i < mtmp; i++) {
      b_DNA_incstr->data[i] = DNA_incstr->data[indx->data[i] - 1];
    }

    str2inc(b_DNA_incstr, inc);
    n = indx->size[1];
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
    mtmp = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i = 0; i < mtmp; i++) {
      edgelist->data[i] = 0.0;
    }

    for (k = 0; k < inc->size[1]; k++) {
      mtmp = inc->size[0];
      for (i = 0; i < mtmp; i++) {
        x_data[i] = (inc->data[i + inc->size[0] * k] == 1.0);
      }

      n = 0;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= mtmp)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= mtmp) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (mtmp == 1) {
        if (n == 0) {
          mtmp = 0;
        }
      } else if (1 > n) {
        mtmp = 0;
      } else {
        mtmp = n;
      }

      for (i = 0; i < mtmp; i++) {
        b_ii_data[i] = ii_data[i];
      }

      for (i = 0; i < 2; i++) {
        edgelist->data[i + edgelist->size[0] * k] = b_ii_data[i];
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
  }

  emxFree_int32_T(&indx);

  /* Functioin */
  /* Function */
  for (i = 0; i < 2; i++) {
    sedgelist[i] = (unsigned int)edgelist->size[i];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(&maxval, 2);
    i = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = edgelist->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, i, (int)sizeof(double));
    for (i = 0; i + 1 <= edgelist->size[1]; i++) {
      ix = i << 1;
      n = (i << 1) + 1;
      mtmp = (int)edgelist->data[ix];
      if (n < ix + 2) {
        while (n + 1 <= ix + 2) {
          if ((int)edgelist->data[n] > mtmp) {
            mtmp = (int)edgelist->data[n];
          }

          n++;
        }
      }

      maxval->data[i] = mtmp;
    }

    n = maxval->size[1];
    mtmp = (int)maxval->data[0];
    if (maxval->size[1] > 1) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int)maxval->data[ix] > mtmp) {
          mtmp = (int)maxval->data[ix];
        }
      }
    }

    emxFree_real_T(&maxval);
    i = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int)sedgelist[1];
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
    mtmp *= (int)sedgelist[1];
    for (i = 0; i < mtmp; i++) {
      inc->data[i] = 0.0;
    }

    for (k = 0; k < (int)sedgelist[1]; k++) {
      for (i = 0; i < 2; i++) {
        inc->data[((int)edgelist->data[i + edgelist->size[0] * k] + inc->size[0]
                   * k) - 1] = 1.0;
      }
    }

    /* For */
  } else {
    i = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
  }

  emxFree_real_T(&edgelist);

  /* If */
}

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                emxArray_real_T *inc
 * Return Type  : void
 */
void e_DNA2inc(const emxArray_real_T *DNA_incstr, const emxArray_real_T
               *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r13;
  int i;
  int mtmp;
  emxArray_int32_T *indx;
  int ix;
  int n;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  unsigned int sedgelist[2];
  emxArray_real_T *maxval;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int b_ii_data[100];
  emxInit_boolean_T(&r13, 2);

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Function */
  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = r13->size[0] * r13->size[1];
  r13->size[0] = 1;
  r13->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)r13, i, (int)sizeof(boolean_T));
  mtmp = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i = 0; i < mtmp; i++) {
    r13->data[i] = (DNA_edgelabel->data[i] == 2.0);
  }

  emxInit_int32_T1(&indx, 2);
  ix = r13->size[1] - 1;
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r13->data[i]) {
      n++;
    }
  }

  i = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = n;
  emxEnsureCapacity((emxArray__common *)indx, i, (int)sizeof(int));
  n = 0;
  for (i = 0; i <= ix; i++) {
    if (r13->data[i]) {
      indx->data[n] = i + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r13);

  /* Switch */
  emxInit_real_T(&edgelist, 2);
  if (!(indx->size[1] == 0)) {
    emxInit_real_T(&b_DNA_incstr, 2);
    i = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = indx->size[1];
    emxEnsureCapacity((emxArray__common *)b_DNA_incstr, i, (int)sizeof(double));
    mtmp = indx->size[0] * indx->size[1];
    for (i = 0; i < mtmp; i++) {
      b_DNA_incstr->data[i] = DNA_incstr->data[indx->data[i] - 1];
    }

    str2inc(b_DNA_incstr, inc);
    n = indx->size[1];
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
    mtmp = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i = 0; i < mtmp; i++) {
      edgelist->data[i] = 0.0;
    }

    for (k = 0; k < inc->size[1]; k++) {
      mtmp = inc->size[0];
      for (i = 0; i < mtmp; i++) {
        x_data[i] = (inc->data[i + inc->size[0] * k] == 1.0);
      }

      n = 0;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= mtmp)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= mtmp) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (mtmp == 1) {
        if (n == 0) {
          mtmp = 0;
        }
      } else if (1 > n) {
        mtmp = 0;
      } else {
        mtmp = n;
      }

      for (i = 0; i < mtmp; i++) {
        b_ii_data[i] = ii_data[i];
      }

      for (i = 0; i < 2; i++) {
        edgelist->data[i + edgelist->size[0] * k] = b_ii_data[i];
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)edgelist, i, (int)sizeof(double));
  }

  emxFree_int32_T(&indx);

  /* Functioin */
  /* Function */
  for (i = 0; i < 2; i++) {
    sedgelist[i] = (unsigned int)edgelist->size[i];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(&maxval, 2);
    i = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = edgelist->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, i, (int)sizeof(double));
    for (i = 0; i + 1 <= edgelist->size[1]; i++) {
      ix = i << 1;
      n = (i << 1) + 1;
      mtmp = (int)edgelist->data[ix];
      if (n < ix + 2) {
        while (n + 1 <= ix + 2) {
          if ((int)edgelist->data[n] > mtmp) {
            mtmp = (int)edgelist->data[n];
          }

          n++;
        }
      }

      maxval->data[i] = mtmp;
    }

    n = maxval->size[1];
    mtmp = (int)maxval->data[0];
    if (maxval->size[1] > 1) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int)maxval->data[ix] > mtmp) {
          mtmp = (int)maxval->data[ix];
        }
      }
    }

    emxFree_real_T(&maxval);
    i = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int)sedgelist[1];
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
    mtmp *= (int)sedgelist[1];
    for (i = 0; i < mtmp; i++) {
      inc->data[i] = 0.0;
    }

    for (k = 0; k < (int)sedgelist[1]; k++) {
      for (i = 0; i < 2; i++) {
        inc->data[((int)edgelist->data[i + edgelist->size[0] * k] + inc->size[0]
                   * k) - 1] = 1.0;
      }
    }

    /* For */
  } else {
    i = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)inc, i, (int)sizeof(double));
  }

  emxFree_real_T(&edgelist);

  /* If */
}

/*
 * File trailer for DNA2inc.c
 *
 * [EOF]
 */
