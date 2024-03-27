from django.shortcuts import redirect

def anonymous_required(view_func):
    def _wrapped_view_func(request, *args, **kwargs):
        if request.user.is_authenticated:
            # Redirige l'utilisateur authentifié vers la page d'accueil
            return redirect('index')
        return view_func(request, *args, **kwargs)
    return _wrapped_view_func