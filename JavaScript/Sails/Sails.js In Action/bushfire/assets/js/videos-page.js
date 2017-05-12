$(function whenDomIsReady() {

    $('.submit-video-form').submit(function (e) {
        e.preventDefault();

        var newVideo = {
            title: $('.submit-video-form input[name="title"]').val(),
            src: $('.submit-video-form input[name="src"]').val()
        };

        $('.submit-video-form input').val('');
        $('.submit-video-form button').text('Submitting...');
        $('.submit-video-form button').prop('disabled', true);

        var parser = document.createElement('a');

        parser.href = newVideo.src;

        var youtubeID = parser.search.substring(parser.search.indexOf('=')+1,
                                                parser.search.length);

        newVideo.src = 'https://www.youtube.com/embed/'+youtubeID;

        setTimeout(function() {
            var newVideoHtml = '<li class="vidoe">' +
                '<h2>' + newVideo.title + '</h2>'+
                '<iframe width="640" height="390" src="'+newVideo.src+'" frameborder ="0" allowfullscreen></iframe>'+
                '</li>';

            $('.the-list-of-videos').prepend(newVideoHtml);
            $('.submit-video-form button').text('Submit video');
            $('.submit-video-form button').prop('disabled', false);
        }, 750);
    });
})

