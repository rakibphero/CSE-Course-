void setup() {
  size(600, 400);
  background(0, 128, 0); // Green background
}

void draw() {
  // Calculate the flag's proportions
  float flagWidth = width;
  float flagHeight = flagWidth * 2 / 3; // Bangladesh flag's aspect ratio is 3:2
  float circleDiameter = flagHeight * 5 / 9;

  // Calculate the position of the circle
  float circleX = flagWidth / 2;
  float circleY = flagHeight / 2;

  // Set fill color to red
  fill(255, 0, 0);
  noStroke();

  // Draw the circle (the red part of the flag)
  ellipse(circleX, circleY, circleDiameter, circleDiameter);
}
