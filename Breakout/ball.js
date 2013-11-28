function ball(x, y,r){
  this.x = x;
  this.y = y;
  //this.w = 100;
  //this.h = 25;
  this.vx=12;
  this.vy=12;
  this.r = r;
  this.b=1;
  this.c0= random_color(); 
 // this.c1="White";

  //this.dude = new Image();
  //this.dude.src = "images/person.png";
}


ball.prototype.draw = function(context){
  //if(this.dude.complete){
  //  context.drawImage(this.dude, this.x, this.y);
  // };
	//this.vy += gravity * 0.1; // v = a * t
    this.x += this.vx * 0.1; // s = v * t
    this.y += this.vy * 0.1;

  	if(this.x + this.r > window.innerWidth){
        this.x = window.innerWidth - this.r;
        this.vx *= -1 * this.b;
    }
    if(this.x - this.r < 0){
        this.x = this.r;
        this.vx *= -1 * this.b;
    }
    if(this.y + this.r > window.innerHeight){
        this.y = window.innerHeight - this.r;
        this.vy *= -1 * this.b;
    }
    if(this.y - this.r < 0){
        this.y = this.r;
        this.vy *= -1 * this.b;
    }
    context.beginPath();
    //context.rect(this.x, this.y, this.w, this.h);
    context.arc(this.x, this.y, this.r, 0, 2 * Math.PI, false);
    context.closePath();  

    var radgrad = context.createRadialGradient(this.x-(this.r*.25),this.y-(this.r*.25),this.r*.01,this.x,this.y,this.r);
    radgrad.addColorStop(0, 'White');
    radgrad.addColorStop(.9, this.c0);
    radgrad.addColorStop(1, 'Black');
    context.fillStyle = radgrad;
    context.fill();
    //stroke
    //ctx.lineWidth = r * 0.1;
    context.strokeStyle = "#000000";
    context.stroke();
};
/*
ball.prototype.update = function(context){
  //if (Key.isDown(Key.UP)) this.moveUp();
  //if (Key.isDown(Key.LEFT)) this.moveLeft();
  //if (Key.isDown(Key.DOWN)) this.moveDown();
  //if (Key.isDown(Key.RIGHT)) this.moveRight();
}

//paddle.prototype.moveUp = function(){
//  this.y -= 2;
//};
//paddle.prototype.moveDown = function(){
//  this.y += 2;
//};
ball.prototype.moveLeft = function(){
  if (this.x >4) this.x -= 5;
};
ball.prototype.moveRight = function(){
  var context = (gamearea);
    //this.x += 5;

  if (this.x< (window.innerWidth-this.w)) 
    this.x +=5;

  else this.x += 0;
};
*/


function random_color(){
          var letter = "0123456789ABCDEF".split("");
          var color = "#";
          for(var i = 0; i < 6; i++){
            color += letter[Math.round(Math.random()*15)];
          }
          return color;
        }