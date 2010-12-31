// A signal is a discrete part of a communication. http://en.wikipedia.org/wiki/Signal
// A sign is an entity which signifies another entity. http://en.wikipedia.org/wiki/Sign

const int DOT = 500;
const int DASH = DOT * 3;
const int CHR_SPC = DOT;
const int LTR_SPC = DOT * 3;
const int WRD_SPC = DOT * 7;

const int LED = 13;

boolean newWord;

char * morsecode[] = { // pointers: http://www.gidforums.com/t-22114.html
  // Numbers
  "-----", // 0 
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----.", // 9
  
  // Special characters (skipped)
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  
  // Letters
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

void dot()
{
  digitalWrite(LED, HIGH);
  delay(DOT);
  charSpace();
}

void dash()
{
  digitalWrite(LED, HIGH);
  delay(DASH);
  charSpace();
}

void charSpace()
{
  
  Serial.println("CHAR SPACE");
  digitalWrite(LED, LOW);
  delay(CHR_SPC);  
}

void letterSpace()
{
  
  Serial.println("LETTER SPACE");
  digitalWrite(LED, LOW);
  delay(LTR_SPC);  
}

void wordSpace()
{
  Serial.println("WORD SPACE");
  digitalWrite(LED, LOW);
  delay(WRD_SPC);
}

void flashSignal(char * morseChar)  // pointer to the value in an index 
                                    // on the morsecode array
{
  Serial.println(morseChar);
  int index = 0;
  while (morseChar[index] != '\0')
  {
    if (morseChar[index] == '-')
    {
      dash();
    }
    if (morseChar[index] == '.')
    {
      dot();
    }
    index++;
  }
}

void readInput(char byte_)
{
  // if the byte is a space, a new word might will come later
  if (byte_ == ' ')
  {
    newWord = true;
  }

  else 
  {
    if 
    (
      (byte_ >= '0' && byte_ <= '9') ||
      (byte_ >= 'A' && byte_ <= 'Z')
    )
    {

      if (newWord)
      {
        newWord = false;
        wordSpace();
      }
      else
      {
        letterSpace();
      }
      
      flashSignal(morsecode[byte_ - '0']);
    }
  }
}

void setup()
{ 
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    readInput(Serial.read());
  }
}