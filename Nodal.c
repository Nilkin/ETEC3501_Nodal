/* proj3.f -- translated by f2c (version 20160102).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

union {
    struct {
	complex yn[1640]	/* was [40][41] */;
	integer nfrom[200], nto[200];
	real type__[200], value[200];
	integer icont[200];
	complex y[200];
	integer nnode, nbr, nn;
	complex j[200], e[200];
    } _1;
    struct {
	complex a[1640]	/* was [40][41] */;
    } _2;
} _BLNK__;

#define _BLNK__1 (_BLNK__._1)
#define _BLNK__2 (_BLNK__._2)

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* THIS PROGRAM PERFORMS AC NODAL ANALYSIS, COMPOSITE BRANCHES ARE USED. */
/* Main program */ int MAIN__(void)
{
    /* Format strings */
    static char fmt_15[] = "(80a1)";
    static char fmt_16[] = "(\0021\002,80a1)";
    static char fmt_6[] = "(i3)";
    static char fmt_7[] = "(3i3,a2,e10.3,i3,4e10.3)";
    static char fmt_8[] = "(e10.3)";
    static char fmt_9[] = "(////1x,\002NO. OF NODES - 1=\002,i2/1x,\002NUMBE"
	    "R OF BRANCHES=\002,i3/1x,\002FREQUENCY OF OPERATION=\002,e10.3//)"
	    ;
    static char fmt_14[] = "(10x,\002THE NETWORK IS DESCRIBED BY THE FOLLOWI"
	    "NG BRANCHES\002///3x,\002I\002,1x,\002FROM\002,1x,\002TO\002,1x"
	    ",\002TYPE\002,2x,\002VALUE\002,3x,\002ICONT\002,7x,\002J\002,20x,"
	    "\002E\002/)";
    static char fmt_10[] = "(\0020\002,3(i3,1x),a2,1x,e10.3,1x,i3,1x,2(1e10."
	    "3,2x,1e10.3,\002J\002,1x))";
    static char fmt_13[] = "(\0021\002,2x,\002***NODE ADMITTANCE MATRIX**"
	    "*\0027x,\002REAL PART\002,3x,\002IMAG PART\002/)";
    static char fmt_18[] = "(\0020\002,\002COLUMN \002,i2)";
    static char fmt_11[] = "(\0020\002,4x,\002(\002,1e10.3,2x,1e10.3,\002J"
	    ")\002)";
    static char fmt_12[] = "(\0020\002//\002 *** EQUIVALENT CURRENT SOURCE V"
	    "ECTOR***\002//)";
    static char fmt_17[] = "(1x,//\002***NODE VOLTAGES***\002//)";
    static char fmt_19[] = "(1x,\002V\002,i2,3x,1e12.4,2x,\002+\002,1e12.4"
	    ",\002J\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, k;
    extern /* Subroutine */ int form_(real *);
    static real omega;
    extern /* Subroutine */ int gauss_(integer *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 5, 0, fmt_15, 0 };
    static cilist io___3 = { 0, 6, 0, fmt_16, 0 };
    static cilist io___4 = { 0, 5, 0, fmt_6, 0 };
    static cilist io___5 = { 0, 5, 0, fmt_7, 0 };
    static cilist io___7 = { 0, 5, 0, fmt_8, 0 };
    static cilist io___9 = { 0, 6, 0, fmt_9, 0 };
    static cilist io___10 = { 0, 6, 0, fmt_14, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___12 = { 0, 6, 0, fmt_13, 0 };
    static cilist io___13 = { 0, 6, 0, fmt_18, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_11, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_12, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_11, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_17, 0 };
    static cilist io___18 = { 0, 6, 0, fmt_19, 0 };


/* READ AND WRITE TITLE */
L1:
    s_rsfe(&io___1);
    for (k = 1; k <= 80; ++k) {
	do_fio(&c__1, (char *)&_BLNK__1.value[k - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_wsfe(&io___3);
    for (k = 1; k <= 80; ++k) {
	do_fio(&c__1, (char *)&_BLNK__1.value[k - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* READ AND WRITE NETWORK INFORMATION */
    _BLNK__1.nnode = 0;
    s_rsfe(&io___4);
    do_fio(&c__1, (char *)&_BLNK__1.nbr, (ftnlen)sizeof(integer));
    e_rsfe();
    i__1 = _BLNK__1.nbr;
    for (k = 1; k <= i__1; ++k) {
	s_rsfe(&io___5);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.nfrom[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&_BLNK__1.nto[i__ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&_BLNK__1.type__[i__ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&c__1, (char *)&_BLNK__1.value[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&_BLNK__1.icont[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__2, (char *)&_BLNK__1.j[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__2, (char *)&_BLNK__1.e[i__ - 1], (ftnlen)sizeof(real));
	e_rsfe();
/* Computing MAX */
	i__2 = _BLNK__1.nnode, i__3 = _BLNK__1.nfrom[i__ - 1], i__2 = max(
		i__2,i__3), i__3 = _BLNK__1.nto[i__ - 1];
	_BLNK__1.nnode = max(i__2,i__3);
/* L2: */
    }
    _BLNK__1.nn = _BLNK__1.nnode + 1;
    s_rsfe(&io___7);
    do_fio(&c__1, (char *)&omega, (ftnlen)sizeof(real));
    e_rsfe();
    s_wsfe(&io___9);
    do_fio(&c__1, (char *)&_BLNK__1.nnode, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&_BLNK__1.nbr, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&omega, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsfe(&io___10);
    e_wsfe();
    i__1 = _BLNK__1.nbr;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L3: */
	s_wsfe(&io___11);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.nfrom[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&_BLNK__1.nto[i__ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&_BLNK__1.type__[i__ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&c__1, (char *)&_BLNK__1.value[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&_BLNK__1.icont[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__2, (char *)&_BLNK__1.j[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__2, (char *)&_BLNK__1.e[i__ - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
/* FORMULATE NODAL EQUATIONS AND SOLVE */
    form_(&omega);
    s_wsfe(&io___12);
    e_wsfe();
    i__1 = _BLNK__1.nnode;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_wsfe(&io___13);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
/* L4: */
	s_wsfe(&io___14);
	i__2 = _BLNK__1.nnode;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__2, (char *)&_BLNK__1.yn[k + i__ * 40 - 41], (ftnlen)
		    sizeof(real));
	}
	e_wsfe();
    }
    s_wsfe(&io___15);
    e_wsfe();
    s_wsfe(&io___16);
    i__2 = _BLNK__1.nnode;
    for (k = 1; k <= i__2; ++k) {
	do_fio(&c__2, (char *)&_BLNK__1.yn[k + _BLNK__1.nn * 40 - 41], (
		ftnlen)sizeof(real));
    }
    e_wsfe();
    gauss_(&_BLNK__1.nnode);
/* PRINT RESULTS */
    s_wsfe(&io___17);
    e_wsfe();
    i__2 = _BLNK__1.nnode;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L5: */
	s_wsfe(&io___18);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__2, (char *)&_BLNK__1.yn[i__ + _BLNK__1.nn * 40 - 41], (
		ftnlen)sizeof(real));
	e_wsfe();
    }
    goto L1;
/* COLLECTION OF FORMAT STATEMENTS */
} /* MAIN__ */

/* Subroutine */ int form_(real *omega)
{
    /* Initialized data */

    static struct {
	char e_1[4];
	real e_2;
	} equiv_32 = { " R  ", 0.f };

#define r__ (*(real *)&equiv_32)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_33 = { " C  ", 0.f };

#define c__ (*(real *)&equiv_33)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_34 = { " G  ", 0.f };

#define g (*(real *)&equiv_34)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_35 = { "VC  ", 0.f };

#define vc (*(real *)&equiv_35)


    /* Format strings */
    static char fmt_53[] = "(\0020\002,\002ERROR IN ELEMENT TYPE\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    real r__1;
    complex q__1, q__2, q__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, k, ia, ib, ic, id, icon;

    /* Fortran I/O blocks */
    static cilist io___26 = { 0, 6, 0, fmt_53, 0 };


/* THIS SUBROUTINE FORMULATES NODE ADMITTANCE MATRIX AND EQUIVALENT */
/* CURRENT SOURCE VECTOR BY DIRECT CONSTRUCTION. */
/* ZERO OUT YN    MATRIX */
    i__1 = _BLNK__1.nnode;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = _BLNK__1.nn;
	for (k = 1; k <= i__2; ++k) {
/* L20: */
	    i__3 = i__ + k * 40 - 41;
	    _BLNK__1.yn[i__3].r = 0.f, _BLNK__1.yn[i__3].i = 0.f;
	}
    }
    i__3 = _BLNK__1.nbr;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* DETERMINE ADMITTANCE TYPE AND VALUE */
	if (_BLNK__1.icont[i__ - 1] != 0) {
	    goto L40;
	}
	_BLNK__1.icont[i__ - 1] = i__;
	if (_BLNK__1.type__[i__ - 1] == r__) {
	    goto L30;
	}
	if (_BLNK__1.type__[i__ - 1] == g) {
	    goto L22;
	}
	if (_BLNK__1.type__[i__ - 1] == c__) {
	    goto L25;
	}
	i__2 = i__ - 1;
	r__1 = -1.f / (*omega * _BLNK__1.value[i__ - 1]);
	q__1.r = 0.f, q__1.i = r__1;
	_BLNK__1.y[i__2].r = q__1.r, _BLNK__1.y[i__2].i = q__1.i;
	goto L60;
L22:
	i__2 = i__ - 1;
	i__1 = i__ - 1;
	q__1.r = _BLNK__1.value[i__1], q__1.i = 0.f;
	_BLNK__1.y[i__2].r = q__1.r, _BLNK__1.y[i__2].i = q__1.i;
	goto L60;
L25:
	i__2 = i__ - 1;
	r__1 = *omega * _BLNK__1.value[i__ - 1];
	q__1.r = 0.f, q__1.i = r__1;
	_BLNK__1.y[i__2].r = q__1.r, _BLNK__1.y[i__2].i = q__1.i;
	goto L60;
L30:
	i__2 = i__ - 1;
	r__1 = 1 / _BLNK__1.value[i__ - 1];
	q__1.r = r__1, q__1.i = 0.f;
	_BLNK__1.y[i__2].r = q__1.r, _BLNK__1.y[i__2].i = q__1.i;
	goto L60;
L40:
	if (_BLNK__1.type__[i__ - 1] == vc) {
	    goto L55;
	}
/* ERROR MESSAGE */
	s_wsfe(&io___26);
	e_wsfe();
	s_stop("", (ftnlen)0);
L55:
	i__2 = i__ - 1;
	i__1 = i__ - 1;
	q__1.r = _BLNK__1.value[i__1], q__1.i = 0.f;
	_BLNK__1.y[i__2].r = q__1.r, _BLNK__1.y[i__2].i = q__1.i;
L60:
	icon = _BLNK__1.icont[i__ - 1];
/* ADD CONTRIBUTIONS TO YN FROM ITH BRANCH */
	ia = _BLNK__1.nfrom[i__ - 1];
	ib = _BLNK__1.nto[i__ - 1];
	ic = _BLNK__1.nfrom[icon - 1];
	id = _BLNK__1.nto[icon - 1];
	if (ia != 0 && ic != 0) {
	    i__2 = ia + ic * 40 - 41;
	    i__1 = ia + ic * 40 - 41;
	    i__4 = i__ - 1;
	    q__1.r = _BLNK__1.yn[i__1].r + _BLNK__1.y[i__4].r, q__1.i = 
		    _BLNK__1.yn[i__1].i + _BLNK__1.y[i__4].i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
	if (ia != 0 && id != 0) {
	    i__2 = ia + id * 40 - 41;
	    i__1 = ia + id * 40 - 41;
	    i__4 = i__ - 1;
	    q__1.r = _BLNK__1.yn[i__1].r - _BLNK__1.y[i__4].r, q__1.i = 
		    _BLNK__1.yn[i__1].i - _BLNK__1.y[i__4].i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
	if (ib != 0 && ic != 0) {
	    i__2 = ib + ic * 40 - 41;
	    i__1 = ib + ic * 40 - 41;
	    i__4 = i__ - 1;
	    q__1.r = _BLNK__1.yn[i__1].r - _BLNK__1.y[i__4].r, q__1.i = 
		    _BLNK__1.yn[i__1].i - _BLNK__1.y[i__4].i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
	if (ib != 0 && id != 0) {
	    i__2 = ib + id * 40 - 41;
	    i__1 = ib + id * 40 - 41;
	    i__4 = i__ - 1;
	    q__1.r = _BLNK__1.yn[i__1].r + _BLNK__1.y[i__4].r, q__1.i = 
		    _BLNK__1.yn[i__1].i + _BLNK__1.y[i__4].i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
/* ADD CONTRIBUTION TO JN FROM ITH BRANCH */
	if (ia != 0) {
	    i__2 = ia + _BLNK__1.nn * 40 - 41;
	    i__1 = ia + _BLNK__1.nn * 40 - 41;
	    i__4 = i__ - 1;
	    q__2.r = _BLNK__1.yn[i__1].r + _BLNK__1.j[i__4].r, q__2.i = 
		    _BLNK__1.yn[i__1].i + _BLNK__1.j[i__4].i;
	    i__5 = i__ - 1;
	    i__6 = icon - 1;
	    q__3.r = _BLNK__1.y[i__5].r * _BLNK__1.e[i__6].r - _BLNK__1.y[
		    i__5].i * _BLNK__1.e[i__6].i, q__3.i = _BLNK__1.y[i__5].r 
		    * _BLNK__1.e[i__6].i + _BLNK__1.y[i__5].i * _BLNK__1.e[
		    i__6].r;
	    q__1.r = q__2.r - q__3.r, q__1.i = q__2.i - q__3.i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
	if (ib != 0) {
	    i__2 = ib + _BLNK__1.nn * 40 - 41;
	    i__1 = ib + _BLNK__1.nn * 40 - 41;
	    i__4 = i__ - 1;
	    q__2.r = _BLNK__1.yn[i__1].r - _BLNK__1.j[i__4].r, q__2.i = 
		    _BLNK__1.yn[i__1].i - _BLNK__1.j[i__4].i;
	    i__5 = i__ - 1;
	    i__6 = icon - 1;
	    q__3.r = _BLNK__1.y[i__5].r * _BLNK__1.e[i__6].r - _BLNK__1.y[
		    i__5].i * _BLNK__1.e[i__6].i, q__3.i = _BLNK__1.y[i__5].r 
		    * _BLNK__1.e[i__6].i + _BLNK__1.y[i__5].i * _BLNK__1.e[
		    i__6].r;
	    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
	    _BLNK__1.yn[i__2].r = q__1.r, _BLNK__1.yn[i__2].i = q__1.i;
	}
/* L70: */
    }
    return 0;
} /* form_ */

#undef vc
#undef g
#undef c__
#undef r__


/* Subroutine */ int gauss_(integer *n)
{
    /* Format strings */
    static char fmt_9[] = "(\002 DETERMINANT EQUAL TO ZERO. NO UNIQUE SOLUTI"
	    "ON.\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    complex q__1, q__2;

    /* Builtin functions */
    double c_abs(complex *);
    void c_div(complex *, complex *, complex *);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static complex b;
    static integer i__, j, k, ic, ip, ir, nm1, np1, nmk;
    static real eps;
    static integer irp1, np1mj;
    static complex pivot;
    static integer ipivot;

    /* Fortran I/O blocks */
    static cilist io___47 = { 0, 6, 0, fmt_9, 0 };


/* THIS SUBROUTINE SOLVES N SIMULTANEOUS LINEAR EQUATIONS BY GAUSSIAN */
/* ELIMINATION METHOD.  ARRAY A IS THE AUGMENTED COEFFICIENT MATRIX, */
/* AT EXIT , THE (N+1)TH COLUMN OF A CONTAINS THE SOLUTIONS. */
    np1 = *n + 1;
    eps = 1e-30f;
/* FORWARD ELIMINATION */
/* SEARCH FOR PIVOT ROW */
    ic = 1;
    ir = 1;
L1:
    i__1 = ir + ic * 40 - 41;
    pivot.r = _BLNK__2.a[i__1].r, pivot.i = _BLNK__2.a[i__1].i;
    ipivot = ir;
    i__1 = *n;
    for (i__ = ir; i__ <= i__1; ++i__) {
	if (c_abs(&_BLNK__2.a[i__ + ic * 40 - 41]) <= c_abs(&pivot)) {
	    goto L2;
	}
	i__2 = i__ + ic * 40 - 41;
	pivot.r = _BLNK__2.a[i__2].r, pivot.i = _BLNK__2.a[i__2].i;
	ipivot = i__;
L2:
	;
    }
/* INTERCHANGE ROWS */
    if (c_abs(&pivot) <= eps) {
	goto L8;
    }
    if (ipivot == ir) {
	goto L4;
    }
    i__1 = np1;
    for (k = ic; k <= i__1; ++k) {
	i__2 = ipivot + k * 40 - 41;
	b.r = _BLNK__2.a[i__2].r, b.i = _BLNK__2.a[i__2].i;
	i__2 = ipivot + k * 40 - 41;
	i__3 = ir + k * 40 - 41;
	_BLNK__2.a[i__2].r = _BLNK__2.a[i__3].r, _BLNK__2.a[i__2].i = 
		_BLNK__2.a[i__3].i;
	i__2 = ir + k * 40 - 41;
	_BLNK__2.a[i__2].r = b.r, _BLNK__2.a[i__2].i = b.i;
/* L3: */
    }
L4:
/* NORMALIZE PIVOT */
    i__1 = np1;
    for (k = ic; k <= i__1; ++k) {
/* L5: */
	i__2 = ir + k * 40 - 41;
	c_div(&q__1, &_BLNK__2.a[ir + k * 40 - 41], &pivot);
	_BLNK__2.a[i__2].r = q__1.r, _BLNK__2.a[i__2].i = q__1.i;
    }
    if (ir == *n) {
	goto L10;
    }
    irp1 = ir + 1;
/* COLUMN REDUCTION */
    i__2 = *n;
    for (ip = irp1; ip <= i__2; ++ip) {
	i__1 = ip + ic * 40 - 41;
	b.r = _BLNK__2.a[i__1].r, b.i = _BLNK__2.a[i__1].i;
	if (c_abs(&b) <= eps) {
	    goto L7;
	}
	i__1 = np1;
	for (k = ic; k <= i__1; ++k) {
	    i__3 = ip + k * 40 - 41;
	    i__4 = ip + k * 40 - 41;
	    i__5 = ir + k * 40 - 41;
	    q__2.r = _BLNK__2.a[i__5].r * b.r - _BLNK__2.a[i__5].i * b.i, 
		    q__2.i = _BLNK__2.a[i__5].r * b.i + _BLNK__2.a[i__5].i * 
		    b.r;
	    q__1.r = _BLNK__2.a[i__4].r - q__2.r, q__1.i = _BLNK__2.a[i__4].i 
		    - q__2.i;
	    _BLNK__2.a[i__3].r = q__1.r, _BLNK__2.a[i__3].i = q__1.i;
/* L6: */
	}
L7:
	;
    }
    ++ir;
    ++ic;
    goto L1;
L8:
    s_wsfe(&io___47);
    e_wsfe();
    s_stop("", (ftnlen)0);
/* BACK SUBSTITUTION */
L10:
    nm1 = *n - 1;
    i__2 = nm1;
    for (k = 1; k <= i__2; ++k) {
	nmk = *n - k;
	i__1 = k;
	for (j = 1; j <= i__1; ++j) {
	    np1mj = *n + 1 - j;
/* L11: */
	    i__3 = nmk + np1 * 40 - 41;
	    i__4 = nmk + np1 * 40 - 41;
	    i__5 = nmk + np1mj * 40 - 41;
	    i__6 = np1mj + np1 * 40 - 41;
	    q__2.r = _BLNK__2.a[i__5].r * _BLNK__2.a[i__6].r - _BLNK__2.a[
		    i__5].i * _BLNK__2.a[i__6].i, q__2.i = _BLNK__2.a[i__5].r 
		    * _BLNK__2.a[i__6].i + _BLNK__2.a[i__5].i * _BLNK__2.a[
		    i__6].r;
	    q__1.r = _BLNK__2.a[i__4].r - q__2.r, q__1.i = _BLNK__2.a[i__4].i 
		    - q__2.i;
	    _BLNK__2.a[i__3].r = q__1.r, _BLNK__2.a[i__3].i = q__1.i;
	}
/* L12: */
    }
    return 0;
} /* gauss_ */

