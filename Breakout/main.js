window.onload = function(){
  var context = (gamearea);
  context.width=window.innerWidth;
  context.height=window.innerHeight;

  Game.initialize(window.innerWidth, window.innerHeight);
  Game.addPlayer(window.innerWidth * .5,window.innerHeight * .9 );

  Game._intervalId = setInterval(Game.run, 0);
};