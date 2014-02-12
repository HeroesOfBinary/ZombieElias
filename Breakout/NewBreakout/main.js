window.onload = function(){
  var context = (gamearea);
  var CANVAS_WIDTH = 480;
  var CANVAS_HEIGHT = 320;

  context.width=CANVAS_WIDTH;
  context.height=CANVAS_HEIGHT;

  Game.initialize(CANVAS_WIDTH, CANVAS_HEIGHT);

  Game.addPlayer(CANVAS_WIDTH * .5,CANVAS_HEIGHT * .9, 150, 25);

  //Game.addBall(0,CANVAS_HEIGHT * .5 ,15)

  Game._intervalId = setInterval(Game.run, 0);
};