from django.shortcuts import render, HttpResponse
import requests
import json

def index(request):
    return HttpResponse('Hello, world!')

def test(request):
    return HttpResponse('My second view!')

def profile(request):
    # if it's a GET request return the HTML template with no data
    # else returns the useful JSON along with the template.
    # This isn't a good approach.
    parsedData =[]    
    if request.method == 'POST':
        username = request.POST.get('user')
        req = requests.get('http://api.github.com/users/' + username)
        data = json.loads(req.text)        
        userData = {}

        userData['email'] = data['email']
        userData['public_gists'] = data['public_gists']
        userData['public_repos'] = data['public_repos']
        userData['avatar_url'] = data['avatar_url']
        userData['followers'] = data['followers']
        userData['following'] = data['following']
        parsedData.append(userData)

    return render(request, 'app/profile.html', {'data': parsedData})