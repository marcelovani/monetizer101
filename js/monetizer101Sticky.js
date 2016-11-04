// add required affiliate link tracking parameters
// full functionality requirements are on ticket #26669
(function() {
  Drupal.behaviors.monetizer101Sticky = {
    attach: function() {
      var sticky = {},
      stickyBlock = document.getElementById('block-monetizer101-monetizer101-sticky'),
      stickyNav = document.getElementById('header-group'),
      iframe= '',
      height = 70,
      startPosition = 0,
      currentPosition = 0,
      moveAmount = 0;

      // update required elements based on amount user has scrolled
      sticky.updateMove = function(amount) {
        iframe.style.top = -height + amount + 'px';
        stickyNav.style.top = amount + 'px';
        document.body.style.marginTop = amount + 'px';
      };

      sticky.scrollMoveIframe = function() {
        // compare currentPosition & startPosition to see how far user has scrolled
        currentPosition = document.documentElement.scrollTop || document.body.scrollTop;
        moveAmount = (currentPosition - startPosition) / 2;
        // if user has scrolled more than height of sticky element fix the element and remove scroll event listener
        if (moveAmount >= height) {
          sticky.updateMove(height);
          removeEventListener('scroll', sticky.scrollMoveIframe);
        }
        // otherwise update elements in sync with user's scroll
        else {
          sticky.updateMove(moveAmount);
        }
      };

      sticky.init = function() {
        // hide wrapping block
        stickyBlock.style.height = 0;
        stickyBlock.style.margin = 0;
        stickyBlock.style.overflow = 'hidden';
        // wait for iframe to load (we don't have access to a proper callback unfortunately)
        setTimeout(function () {
          // set fixed position styles on iframe
          iframe = stickyBlock.querySelector('iframe');
          iframe.style.position = 'fixed';
          iframe.style.top = -height + 'px';
          iframe.style.left = 0;
          iframe.style.right = 0;
          iframe.style.width = '100%';
          iframe.style.height = height + 'px';
          iframe.style.zIndex = 500;
          iframe.style.backgroundColor = 'white';
          // set start position & add scroll event listener
          startPosition = document.documentElement.scrollTop || document.body.scrollTop;
          addEventListener('scroll', sticky.scrollMoveIframe);
        }, 7000);
      };

      return sticky.init();
    }
  };
})();
