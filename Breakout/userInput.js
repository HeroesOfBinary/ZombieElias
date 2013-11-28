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
*/

window.addEventListener('keyup', function(event) { Key.onKeyup(event); }, false);
window.addEventListener('keydown', function(event) { Key.onKeydown(event); }, false);
//window.addEventListener("resize", resize_canvas(canvas));
//$(window).bind("resize", resizeWindow);
