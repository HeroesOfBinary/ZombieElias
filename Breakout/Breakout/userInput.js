var Key = {
  _pressed: {},

  LEFT: 37,
  UP: 38,
  RIGHT: 39,
  DOWN: 40,

  isDown: function(keyCode){
    return this._pressed[keyCode];
  },

  onKeydown: function(event){
    this._pressed[event.keyCode] = true;
  },

  onKeyup: function(event){
    delete this._pressed[event.keyCode];
  }
};
/*
  function resize_canvas(){
      //var canvas = document.getElementById("gamearea").getContext("2d");
      if (canvas.width  < window.innerWidth)
      {
          canvas.width  = window.innerWidth;
      }

      if (canvas.height < window.innerHeight)
      {
          canvas.height = window.innerHeight;
      }
  }


this.overlap = function(o1,o2) {
return !((o1.y+o1.h-1<o2.y) || (o1.y>o2.y+o2.h-1) ||
(o1.x+o1.w-1<o2.x) || (o1.x>o2.x+o2.w-1));
};

this.collide = function(obj,type) {
  return this.detect(function() {
    if(obj != this) {
      var col = (!type || this.type & type) && board.overlap(obj,this)
      return col ? this : false;
    }
  });
};
*/
window.addEventListener('keyup', function(event) { Key.onKeyup(event); }, false);
window.addEventListener('keydown', function(event) { Key.onKeydown(event); }, false);
//window.addEventListener("resize", resize_canvas(canvas));
//$(window).bind("resize", resizeWindow);
