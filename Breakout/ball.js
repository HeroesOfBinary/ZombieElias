function ball(x, y,r){
  this.x = x;
  this.y = y;
  //this.w = 100;
  //this.h = 25;
  this.vx=100;
  this.vy=0;
  this.r = r;
  this.b=1;
  this.size=100;
  this.c0= random_color(); 
  this.collision = checkCollisionWith;
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
    
    if (this.collision(context.Paddle))	alert("Sucess");

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
function checkCollisionWith(obj){
  // If the two objects are less the sum of their collision radii apart then they have collided
  // Note that one obj is obj (with a loc and a size) and the other is this.
  // Returns true if the objects are touching
  alert(obj.size);
  var dist = this.size + obj.size; // The distance they must be apart to be not touching
  if(obj.x-this.x>dist || obj.x-this.x<-dist)
    return false; // Too far apart in x plane
  if(obj.y-this.y>dist || obj.y-this.y<-dist)
    return false; // Too far apart in y plane
  
  var xDist = Math.abs(obj.x-this.x);
  var yDist = Math.abs(obj.y-this.y);
  
  var hyp = Math.sqrt((xDist*xDist)+(yDist*yDist));

  if(hyp<dist)
    return true;

  return false;
  
}

function random_color(){
          var letter = "0123456789ABCDEF".split("");
          var color = "#";
          for(var i = 0; i < 6; i++){
            color += letter[Math.round(Math.random()*15)];
          }
          return color;
        }