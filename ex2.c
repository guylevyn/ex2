/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
  int x ;
    do {
        printf("Choose an option:\n"
        "     1. Happy Face \n"
        "     2. Balanced Number \n"
        "     3. Generous Number \n"
        "     4. Circle Of Joy \n"
        "     5. Happy Numbers \n"
        "     6. Festival Of Laughter \n"
        "     7. Exit \n");
        scanf("%d", &x);
        switch (x) {
            // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
            /* Example:
            * n = 3:
            * 0   0
            *   o
            * \___/
            */
            case 1: printf("Enter symbols for the eyes, nose, and mouth:\n");
            char eyes,nose,mouth;
            int size;
            scanf(" %c %c %c", &eyes, &nose, &mouth);
            printf("Enter face size:\n");
            scanf(" %d" ,&size);
            //בדיקה עם הקלט עונה לדרישה
            while (size%2 == 0 || size<=0) {
                printf("The face's size must be an odd and positive number, please try again:\n");
                scanf(" %d" ,&size);
            }
            //הדפסה של החלק העליון
            printf("%c",eyes);
            for (int i = 0; i < size; i++) {
                printf(" ");
            }
            printf("%c \n",eyes);
            // הדפסה של החלק האמצעי
            for (int i = 0; i <= (size/2); i++) {
                printf(" ");
            }
            printf("%c\n",nose);
            //הדפסה של חלק תחתון
            printf("\\");
            for (int i = 0; i < size; i++) {
                printf("%c",mouth);
            }
            printf("/\n");
            break;

            // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
            // and the sum of all digits to the right of the middle digit(s) are equal
            /* Examples:
            Balanced: 1533, 450810, 99
            Not blanced: 1552, 34
            Please notice: the number has to be bigger than 0.
            */
            case 2: printf("Enter a number:\n");
            int BalancedNum;
            scanf("%d",&BalancedNum);
            //בדיקה אם הקלט עונה על הדרישות
            while (BalancedNum<=0) {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d",&BalancedNum);
            }
            int sum1=0 ,sum2=0;
            int numOfNums = 0;
            int copyBalNum = BalancedNum,copyBalNum1 = BalancedNum;
            // בדיקה כמה איברים יש בקלט
            while (copyBalNum>0) {
                copyBalNum = copyBalNum/10;
                numOfNums++;
            }
            // פיצול של הסכימה למקרה ומספר האיברים בקלט זוגי ואי זוגי
            if (numOfNums%2==0) {
                for (int i = 1; i <= numOfNums; i++) {
                    if (i<=(numOfNums/2))
                        sum1 = sum1 + copyBalNum1%10;
                    else
                        sum2 = sum2 + copyBalNum1%10;
                    copyBalNum1 = copyBalNum1/10;
                }
            }
            else {
                for (int i = 1; i <= numOfNums; i++) {
                    if (i==((numOfNums+1)/2)) {
                        sum1 = sum1 + copyBalNum1%10;
                        sum2 = sum2 + copyBalNum1%10;
                    }
                    else if (i<((numOfNums+1)/2))
                        sum1 = sum1 + copyBalNum1%10;
                    else
                        sum2 = sum2 + copyBalNum1%10;
                    copyBalNum1 = copyBalNum1/10;
                }
            }
            // בדיקה אם הסכומים שווים
            if (sum1==sum2)
                printf("This number is balanced and brings harmony!\n");
            else printf("This number isn't balanced and destroys harmony.\n");
            break;

            // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
            /* Examples:
            Abudant: 12, 20, 24
            Not Abudant: 3, 7, 10
            Please notice: the number has to be bigger than 0.
            */
            case 3: printf("Enter a number:\n");
            int generousNum;
            int sumOfDivisors = 0;
            scanf("%d",&generousNum);
            //בדיקה אם הקלט עונה על הדרישות
            while (generousNum<=0) {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d",&generousNum);
            }
            //בדיקה אם i מחלק אותו נוסיף אותו לסכום
            for (int i = 2; i < generousNum; i++) {
                if (generousNum%i==0)
                  sumOfDivisors = sumOfDivisors + i;
            }
            // בדיקה אם סכום המחלקים גדול מהמספר
            if (sumOfDivisors>generousNum)
                printf("This number is generous!\n");
            else printf("This number does not share.\n");
            break;

            // Case 4: determine wether a number is a prime.
            /* Examples:
            This one brings joy: 3, 5, 11
            This one does not bring joy: 15, 8, 99
            Please notice: the number has to be bigger than 0.
            */
            case 4: printf("Enter a number:\n");
            int prime;
            scanf("%d",&prime);
            // בדיקה אם הקלט עונה על הדרישות
            while (prime<=0) {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d",&prime);
            }
            int countOfNumbers=1;
            int reversedPrime = 0;
            int copyPrime = prime, copyPrime1 = prime;
            // בדיקה כמה איברים יש בקלט ונהפוך את הקאונט שלנו למספר מתחלק ב10 עם אותה כמות
            while (copyPrime>10) {
                copyPrime = copyPrime/10;
                countOfNumbers = countOfNumbers*10;
            }
            // תהליך ההפיכה של הקלט
            while (copyPrime1>0) {
                reversedPrime = reversedPrime + (copyPrime1%10)*countOfNumbers;
                countOfNumbers = countOfNumbers/10;
                copyPrime1 = copyPrime1/10;
            }
            int count =0;
            // בדיקה אם יש לקלט ולהופכי מחלקים
            for (int i = 2; i < reversedPrime; i++) {
                if (reversedPrime%i==0)
                    count++;
            }
            for (int i = 2; i < prime; i++) {
                if (prime%i==0)
                    count++;
            }
            // בדיקה אם היה מחלקים או שהקלט הוא 1
            if (prime==1)
                printf("The circle remains incomplete.\n");
            else if (count==0)
                printf("This number completes the circle of joy!\n");
            else
                printf("The circle remains incomplete.\n");
            break;

            // Happy numbers: Print all the happy numbers between 1 to the given number.
            // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
            /* Examples:
            Happy :) : 7, 10
            Not Happy :( : 5, 9
            Please notice: the number has to be bigger than 0.
            */
            case 5: printf("Enter a number:\n");
            int happyNum;
            scanf("%d",&happyNum);
            // בדיקה אם הקלט עונה על הדרישות
            while (happyNum<=0) {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d",&happyNum);
            }
            printf("numbers bring happiness:");
            //ריצה עד הקלט המבוקש
            for (int i = 1; i <= happyNum; i++) {
                int firstSum=0;
                int copyOfHappy = i;
                //בדיקה של הסכום בפעם הראשונה
                while (copyOfHappy>0) {
                    firstSum = firstSum + (copyOfHappy%10)*(copyOfHappy%10);
                    copyOfHappy = copyOfHappy/10;
                }
                //אין מה לבדוק עבור הסכום הראשון כיוון שאם הוא 1 בהמשך קטע הקוד סכום הריבועים עדין ישאר 1 וגם אם הוא 4 הוא יחזור על הללופ בהמשך שוב
                int secondSum=0;
                while (1>0) {
                    // הסכום השני תמיד יהיה הסכום החדש
                    secondSum = secondSum + (firstSum%10)*(firstSum%10);
                    firstSum = firstSum/10;
                    // אם הסכום הראשון התאפס כלומר עברנו מחזור נבדוק אם הסכום הוא 1 ונדפיסו או 4 ונתקענו בלופ היחיד לכן לא נדפיס
                    if (firstSum==0) {
                        if (secondSum==4) {
                            break;
                        }
                        if (secondSum==1) {
                            printf(" %d",i);
                            break;
                        }
                        // נעשה החלפה בין המשתנים על מנת שסכום 2 תמיד יהיה החדש
                        firstSum = secondSum;
                        secondSum = 0;
                    }
                }
            }
            printf("\n");
            break;

            // Festival of Laughter: Prints all the numbers between 1 the given number:
            // and replace with "Smile!" every number that divided by the given smile number
            // and replace with "Cheer!" every number that divided by the given cheer number
            // and replace with "Festival!" every number that divided by both of them
            /* Example:
            6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
            */
            case 6: printf("Enter a smile and cheer number: \n");
            int smile,cheer;
            // לולאה אינסופית שתמשיך לרוץ עד לברייק
            while (1) {
                // בדיקה אם הקלט עונה לתנאים אם כן שימשיך להמשך התכנית
                if (scanf(" smile: %d, cheer: %d", &smile, &cheer) == 2 && smile > 0 && cheer > 0 && smile != cheer) {
                    break;;
                }
                else {
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    //על מנת למנוע השארה של הקליטות הקודמות וליצור מצב של תקלות או לולאות אינסופיות בכל פעם שהתנאי נכשל ננקה את הבאפר כך:
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }
            int n;
            printf("Enter maximum number for the festival: \n");
            scanf(" %d",&n);
            while (n<=0) {
                printf("Only positive maximum number is allowed, please try again:\n");
                scanf(" %d",&n);
            }
            for (int i = 1; i <= n; i++) {
                if ((i%cheer)==0 && (i%smile)==0)
                    printf("Festival!\n");
                else if ((i%cheer)==0)
                    printf("Cheer!\n");
                else if ((i%smile)==0)
                    printf("Smile!\n");
                else
                    printf("%d \n",i);
            }
            break;


            case 7: printf("Thank you for your journey through Numeria!\n");
            break;

            default: printf("This option is not available, please try again.\n");
        }
    } while (x!=7);

	return 0;
}
