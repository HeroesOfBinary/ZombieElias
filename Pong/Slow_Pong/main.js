window.onload = function(){
  var context = (gamearea);
  context.width=window.innerWidth;
  context.height=window.innerHeight;

  Game.initialize(window.innerWidth, window.innerHeight);
  Game.addPlayer(window.innerWidth * .01,window.innerHeight * .5, 125, 25 );
  Game.addPlayer(window.innerWidth * .99- 25,window.innerHeight * .5, 125, 25 );

  //Game.addBall(25,25,15)
  Game.addBall(window.innerWidth * .5,window.innerHeight * .5 ,15)
  Game._intervalId = setInterval(Game.run, 0);
};