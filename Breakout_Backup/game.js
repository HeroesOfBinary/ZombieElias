var Game = {};

Game.fps = 80;

Game.initialize = function(height,width) {
 
  this.entities = [];
  this.context = document.getElementById("gamearea").getContext("2d"); 

};

Game.draw = function(){
  this.context.clearRect(0,0,window.innerWidth,window.innerHeight);
  for(var i = 0; i < this.entities.length; i++){
    this.entities[i].draw(this.context);
  }
};

Game.update = function(){
  this.entities[0].update(this.context);
};

Game.addPlayer = function(x, y){
  Game.entities.push(new paddle(x, y));
};

Game.addBall = function(x, y, r){
  Game.entities.push(new ball(x, y,r));
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



