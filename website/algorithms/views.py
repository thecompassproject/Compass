from django.http import HttpResponse
from django.template import loader
import build.Debug.example as example


def algorithms(request):
    if request.GET.get('mass') is not None:
        mass = float(request.GET.get('mass'))
    else:
        mass = 0

    if request.GET.get('angle') is not None:
        angle = float(request.GET.get('angle'))
    else:
        angle = 0

    if request.GET.get('velocity') is not None:
        velocity = float(request.GET.get('velocity'))
    else:
        velocity = 0

    if request.GET.get('drag') is not None:
        drag = float(request.GET.get('drag'))
    else:
        drag = 0

    # Get result from a CPP function
    result = example.add(mass, angle, velocity, drag)
    context = {
        'result': result,
    }
    template = loader.get_template('samreet.html')
    return HttpResponse(template.render(context, request))