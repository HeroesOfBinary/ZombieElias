var Game = {};

Game.fps = 80;

Game.initialize = function(height,width) {
 
  this.balls = [];
  this.paddles = [];
  this.context = document.getElementById("gamearea").getContext("2d"); 

};

Game.draw = function(){
  this.context.clearRect(0,0,window.innerWidth,window.innerHeight);

  for(var i = 0; i < this.paddles.length; i++){
    //paddles.forEach(function(enemy) {
    this.paddles[i].draw(this.context);
  }

  for(var i = 0; i < this.balls.length; i++){
    this.balls[i].draw(this.context);
  }
};

Game.update = function(){
  //this.paddles[0].update(this.context);
    for(var i = 0; i < this.paddles.length; i++){
    this.paddles[i].update(this.context);
  }
};

Game.addPlayer = function(x, y){
  Game.paddles.push(new paddle(x, y));
};

Game.addBall = function(x, y, r){
  Game.balls.push(new ball(x, y,r));
};

Game.run = (function(){
  var loops = 0, skipTicks = 1000 / Game.fps,
  maxFrameSkip = 10,
  nextGameTick = (new Date).getTime();




return function() {
  loops = 0;

  while ((new Date).getTime() > nextGameTick && loops < maxFrameSkip) {
    Game.update();
    nextGameTick += skipTicks;
    loops++;
  }

  Game.draw();
};
})();



