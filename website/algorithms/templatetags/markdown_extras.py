from django import template
from django.template.defaultfilters import stringfilter
import markdown as md

register = template.Library()

def get_file_content(file_name):
    content = ""
    with open('algorithms/programcodes/'+file_name) as f:
        content = f.read()
    return content


@register.filter()
@stringfilter
def markdown(file_name):
    content = get_file_content(file_name)
    return md.markdown(content, extensions=['markdown.extensions.fenced_code', 'codehilite'])
