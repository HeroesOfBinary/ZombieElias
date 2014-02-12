function paddle(x, y, w, h){
  this.x = x;
  this.y = y;
  this.w = w;
  this.h = h;
  this.shape = "rectangle";
  this.c = random_color(); 
  this.type = "Paddle"
}


paddle.prototype.draw = function(context){
  //if(this.dude.complete){
  //  context.drawImage(this.dude, this.x, this.y);
  // };
    context.beginPath();
    context.rect(this.x, this.y, this.w, this.h);
    context.closePath();  

    context.fillStyle = this.c;
    context.fill();

    context.strokeStyle = "#000000";
    context.stroke();
};

paddle.prototype.update = function(context){
  //if (Key.isDown(Key.UP)) this.moveUp();
  if (Key.isDown(Key.LEFT)) this.moveLeft();
  //if (Key.isDown(Key.DOWN)) this.moveDown();
  if (Key.isDown(Key.RIGHT)) this.moveRight();
}

//paddle.prototype.moveUp = function(){
//  this.y -= 2;
//};
//paddle.prototype.moveDown = function(){
//  this.y += 2;
//};
paddle.prototype.moveLeft = function(){
  if (this.x >4) this.x -= 5;
};
paddle.prototype.moveRight = function(){
    //this.x += 5;

  if (this.x< (window.innerWidth-this.w)) 
    this.x +=5;

  else this.x += 0;
};



function random_color(){
          var letter = "0123456789ABCDEF".split("");
          var color = "#";
          for(var i = 0; i < 6; i++){
            color += letter[Math.round(Math.random()*15)];
          }
          return color;
        }