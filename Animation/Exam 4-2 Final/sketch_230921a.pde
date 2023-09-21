ArrayList<Triangle> triangles = new ArrayList<Triangle>();
ArrayList<Rectangle> rectangles = new ArrayList<Rectangle>();
ArrayList<Circle> circles = new ArrayList<Circle>();

void setup() {
  size(800, 600);
  
  // Initialize triangles
  for (int i = 0; i < 5; i++) {
    triangles.add(new Triangle(random(width), random(height)));
  }
  
  // Initialize rectangles
  for (int i = 0; i < 5; i++) {
    rectangles.add(new Rectangle(random(width), random(height)));
  }
  
  // Initialize circles
  for (int i = 0; i < 5; i++) {
    circles.add(new Circle(random(width), random(height)));
  }
}

void draw() {
  background(255);
  
  // Update and display triangles
  for (Triangle t : triangles) {
    t.update();
    t.display();
  }
  
  // Update and display rectangles
  for (Rectangle r : rectangles) {
    r.update();
    r.display();
  }
  
  // Update and display circles
  for (Circle c : circles) {
    c.update();
    c.display();
  }
}

void mousePressed() {
  // Change rotation direction on mouse press
  for (Triangle t : triangles) {
    t.changeRotationDirection();
  }
  for (Rectangle r : rectangles) {
    r.changeRotationDirection();
  }
  for (Circle c : circles) {
    c.changeRotationDirection();
  }
}

class Triangle {
  float x, y;
  float angle = 0;
  float rotationSpeed = random(0.02, 0.05);
  color col = color(random(255), random(255), random(255));
  
  Triangle(float x, float y) {
    this.x = x;
    this.y = y;
  }
  
  void update() {
    angle += rotationSpeed;
  }
  
  void display() {
    pushMatrix();
    translate(x, y);
    rotate(angle);
    fill(col);
    triangle(-20, 20, 20, 20, 0, -30);
    popMatrix();
  }
  
  void changeRotationDirection() {
    rotationSpeed *= -1;
  }
}

class Rectangle {
  float x, y;
  float angle = 0;
  float rotationSpeed = random(0.02, 0.05);
  color col = color(random(255), random(255), random(255));
  
  Rectangle(float x, float y) {
    this.x = x;
    this.y = y;
  }
  
  void update() {
    angle += rotationSpeed;
  }
  
  void display() {
    pushMatrix();
    translate(x, y);
    rotate(angle);
    fill(col);
    rect(-15, -15, 30, 30);
    popMatrix();
  }
  
  void changeRotationDirection() {
    rotationSpeed *= -1;
  }
}

class Circle {
  float x, y;
  float angle = 0;
  float rotationSpeed = random(0.02, 0.05);
  color col = color(random(255), random(255), random(255));
  
  Circle(float x, float y) {
    this.x = x;
    this.y = y;
  }
  
  void update() {
    angle += rotationSpeed;
  }
  
  void display() {
    pushMatrix();
    translate(x, y);
    rotate(angle);
    fill(col);
    ellipse(0, 0, 30, 30);
    popMatrix();
  }
  
  void changeRotationDirection() {
    rotationSpeed *= -1;
  }
}
