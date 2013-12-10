function ball(x, y,r){
  this.x = x;
  this.y = y;
  //this.w = 100;
  //this.h = 25;
  this.vx=25;
  this.vy=25;
  this.r = r;
  this.b=1;
  this.size=100;
  this.c0= random_color(); 
  this.shape = "circle";
  this.collided = false;

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
    

    checkForCollisions(this);
    /*
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
    */
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
function collides(a, b) {
  return a.x < b.x + b.width &&
    a.x + a.width > b.x &&
    a.y < b.y + b.height &&
    a.y + a.height > b.y;
}

function handleCollisions() {
  playerBullets.forEach(function(bullet) {
    enemies.forEach(function(enemy) {
      if(collides(bullet, enemy)) {
        enemy.explode();
        bullet.active = false;
      }
    });
  });
*/
function checkForCollisions(obj) 
{       
  //ar paddleObjects = Game.paddles;

  //alert(paddleObjects.length);
  for(var i = 0; i < Game.paddles.length; i++){
    // this.paddles[i].draw(this.context);
    checkCircleRectangleCollisions(obj,Game.paddles[i])

}


}
 function checkCircleRectangleCollisions(firstObj,checkObj)
 {

    var leftEdge = checkObj.x;
    var rightEdge = checkObj.x + checkObj.w;
    var topEdge = checkObj.y;
    var bottomEdge = checkObj.y + checkObj.h;

    if ((firstObj.x+firstObj.r)>=leftEdge && 
      firstObj.y+firstObj.r>=topEdge && 
      firstObj.y-firstObj.r <= bottomEdge && 
      firstObj.x-firstObj.r<=rightEdge)
    {
      if (firstObj.collided == false)
      {
                firstObj.collided = true;
      if (firstObj.x+firstObj.r<leftEdge)
        {
          firstObj.vx*=-1 * firstObj.b;
        }
       else if (firstObj.x-firstObj.r>rightEdge )
       {
          firstObj.vy*=-1 * firstObj.b;
       }
       else
      {
        //firstObj.vx*=-1 * firstObj.b;
        //Distance Formula 

        if ((Math.pow(firstObj.x - leftEdge,2) + Math.pow(firstObj.y - topEdge))-firstObj.r<0 )
        {
           firstObj.vx*=-1 * firstObj.b;
           firstObj.vy*=-1 * firstObj.b;
        }
        else if ((Math.pow(firstObj.x - leftEdge,2) + Math.pow(firstObj.y - bottomEdge))-firstObj.r<0 )
        {
           firstObj.vx*=-1 * firstObj.b;
           firstObj.vy*=-1 * firstObj.b;
         }
        else if ((Math.pow(firstObj.x - rightEdge,2) + Math.pow(firstObj.y - topEdge))-firstObj.r<0 )
        {
           firstObj.vx*=-1 * firstObj.b;
           firstObj.vy*=-1 * firstObj.b;
        }
        else if ((Math.pow(firstObj.x - rightEdge,2) + Math.pow(firstObj.y - bottomEdge))-firstObj.r<0 )
        {
           firstObj.vx*=-1 * firstObj.b;
           firstObj.vy*=-1 * firstObj.b;
        }
        else 
        {
            firstObj.vy*=-1 * firstObj.b;
        }
        
      }
      //firstObj.vx*=-1 * firstObj.b;
      //firstObj.vy*=-1 * firstObj.b;
      }

    }
    else
    {
      if(firstObj.x + firstObj.r > window.innerWidth){
      firstObj.x = window.innerWidth - firstObj.r;
      firstObj.vx *= -1 * firstObj.b;
    }
      else if (firstObj.x - firstObj.r < 0){
        firstObj.x = firstObj.r;
        firstObj.vx *= -1 * firstObj.b;
    }
      else if (firstObj.y + firstObj.r > window.innerHeight){
        firstObj.y = window.innerHeight - firstObj.r;
        firstObj.vy *= -1 * firstObj.b;
    }
      else if (firstObj.y - firstObj.r < 0){
        firstObj.y = firstObj.r;
        firstObj.vy *= -1 * firstObj.b;
    }
      else 
      {
        firstObj.collided = false;
      }
    }

 }
 

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



function checkCollisionWith(obj){
  // If the two objects are less the sum of their collision radii apart then they have collided
  // Note that one obj is obj (with a loc and a size) and the other is this.
  // Returns true if the objects are touching
  //alert(this.x);
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
*/


function random_color(){
          var letter = "0123456789ABCDEF".split("");
          var color = "#";
          for(var i = 0; i < 6; i++){
            color += letter[Math.round(Math.random()*15)];
          }
          return color;
        }