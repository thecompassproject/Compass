from django.http import HttpResponse
from django.template import loader
import build.Debug.cpp_function as cpp_function


def algorithms(request):

    prog_choice = request.GET.get('prog_choice')
    if prog_choice is not None and len(prog_choice) > 0:
        prog_choice = float(prog_choice)
    else:
        prog_choice = 0

    V0 = request.GET.get('V0')
    if V0 is not None and len(V0) > 0:
        V0 = float(V0)
    else:
        V0 = 0

    r = request.GET.get('r')
    if r is not None and len(r) > 0:
        r = float(r)
    else:
        r = 0

    th = request.GET.get('th')
    if th is not None and len(th) > 0:
        th = float(th)
    else:
        th = 0

    c = request.GET.get('c')
    if c is not None and len(c) > 0:
        c = float(c)
    else:
        c = 0

    m = request.GET.get('m')
    if m is not None and len(m) > 0:
        m = float(m)
    else:
        m = 0

    val = request.GET.get('val')
    if val is not None and len(val) > 0:
        val = float(val)
    else:
        val = 0

    L = request.GET.get('L')
    if L is not None and len(L) > 0:
        L = float(L)
    else:
        L = 0

    C = request.GET.get('C')
    if C is not None and len(C) > 0:
        C = float(C)
    else:
        C = 0

    R = request.GET.get('R')
    if R is not None and len(R) > 0:
        R = float(R)
    else:
        R = 0

    initialTime = request.GET.get('initialTime')
    if initialTime is not None and len(initialTime) > 0:
        initialTime = float(initialTime)
    else:
        initialTime = 0

    finalTime = request.GET.get('finalTime')
    if finalTime is not None and len(finalTime) > 0:
        finalTime = float(finalTime)
    else:
        finalTime = 0

    I = request.GET.get('I')
    if I is not None and len(I) > 0:
        I = float(I)
    else:
        I = 0

    Q = request.GET.get('Q')
    if Q is not None and len(Q) > 0:
        Q = float(Q)
    else:
        Q = 0

    n = request.GET.get('n')
    if n is not None and len(n) > 0:
        n = float(n)
    else:
        n = 0

    m1 = request.GET.get('m1')
    if m1 is not None and len(m1) > 0:
        m1 = float(m1)
    else:
        m1 = 0

    m2 = request.GET.get('m2')
    if m2 is not None and len(m2) > 0:
        m2 = float(m2)
    else:
        m2 = 0

    l1 = request.GET.get('l1')
    if l1 is not None and len(l1) > 0:
        l1 = float(l1)
    else:
        l1 = 0

    l2 = request.GET.get('l2')
    if l2 is not None and len(l2) > 0:
        l2 = float(l2)
    else:
        l2 = 0

    o11 = request.GET.get('o11')
    if o11 is not None and len(o11) > 0:
        o11 = float(o11)
    else:
        o11 = 0

    o22 = request.GET.get('o22')
    if o22 is not None and len(o22) > 0:
        o22 = float(o22)
    else:
        o22 = 0

    g = request.GET.get('g')
    if g is not None and len(g) > 0:
        g = float(g)
    else:
        g = 0

    # Get result from a CPP function
    result = cpp_function.run(prog_choice, val, m, r, V0, th, c,
                              L, C, R, initialTime, finalTime, I, Q, n,
                              m1, m2, l1, l2, o11, o22, g)
    context = {
        'result': result,
        'm': m,
        'r': r,
        'th': th,
        'V0': V0,
        'c': c,
        'val': val,
        'prog_choice': prog_choice,
        'L': L,
        'C': C,
        'R': R,
        'initialTime': initialTime,
        'finalTime': finalTime,
        'I': I,
        'Q': Q,
        'n': n,
        'm1': m1,
        'm2': m2,
        'l1': l1,
        'l2': l2,
        'o11': o11,
        'o22': o22,
        'g': g
    }
    template = loader.get_template('samreet.html')
    return HttpResponse(template.render(context, request))
