float x = 200; // Initial X-coordinate
float y = 200; // Initial Y-coordinate
float speed = 2; // Speed of movement

void setup() {
  size(400, 400);
  textSize(32); // Set text size
}

void draw() {
  background(200); // Clear the background
  
  // Display the text at the current position (x, y)
  text("Move Rakib", x, y);
  
  // Move the text left, right, top, or bottom based on user input
  if (keyPressed) {
    if (key == 'a' || key == 'A') {
      x -= speed; // Move left
    }
    if (key == 'd' || key == 'D') {
      x += speed; // Move right
    }
    if (key == 'w' || key == 'W') {
      y -= speed; // Move up
    }
    if (key == 's' || key == 'S') {
      y += speed; // Move down
    }
  }
}
