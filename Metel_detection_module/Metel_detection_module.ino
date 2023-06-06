/*  Minesweeper Graduation project 2023 
 *   Metel_detection_Module
 *   Mechatronic depertment "Level 5"
 *   Egyptian chinese university
 *   ECU
 *   Author:
 *   Eng/Kirollos Gerges
 */

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int metel_detection = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(metel_detection);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined

   if (metel_detection >= 0  ||  metel_detection < 100  )
  {
    Serial.println(" The Mine is on ground");
  } 
  else if (metel_detection >= 300) 
  {
    Serial.println("The Mine is underground ");
  } 
  else 
  {
    Serial.println("No Mines found ");
  }

  delay(500);
}
