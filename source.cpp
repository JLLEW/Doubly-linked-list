#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Caterpillar {
	struct node {
		char data;
		node* next;
		node* prev;
	};
public:
	node * head, *tail;
	int posx, posy, lengthOfCaterpillar;
	char**fieldToScan;

	Caterpillar(char* modules, int x, int y)
		: posx(x), posy(y), lengthOfCaterpillar(0)
	{
		head = (node*)malloc(sizeof(node));
		head->next = NULL;
		head->data = NULL;
		head->prev = NULL;
		tail = (node*)malloc(sizeof(node));
		tail = head;
		int i = 0;
		while (modules[i] != NULL) {
			addToTheEnd(modules[i]);
			i++;
		}
	}

	void addAtBeggining(char d) {
		lengthOfCaterpillar++;
		node *newNode = (node*)malloc(sizeof(node));
		head->data = d;
		newNode->next = head;
		newNode->prev = NULL;
		head->prev = newNode;
		head = newNode;

	}

	void addToTheEnd(char d) {
		lengthOfCaterpillar++;
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = d;
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	void deleteFromTail() {
		lengthOfCaterpillar--;
		node *temp = tail->prev;
		tail->prev->next = NULL;
		free(tail);
		tail = temp;
	}

	void deleteFromHead() {
		lengthOfCaterpillar--;
		node* temp = head->next;
		free(head);
		head = temp;
	}

	void print() {
		node *temp = head;
		printf("%d %d ", posx, posy);
		if (temp->next != NULL) {
			while (temp->next != NULL) {
				temp = temp->next;
				printf("%c", temp->data);
			}
		}
		else
			printf("#");
		printf("\n");
	}

	void scanner(char**fieldToScan, int width, int height, int duration) {
		int moveDir = 4, x, y;
		for (int d = 0; d < duration; d++) {
			x = (posx - 1) % width;
			y = (posy - 1) % height;
			while (x < 0) {
				x += width;
			}
			while (y < 0) {
				y += height;
			}
			switch (moveDir) {
			case 1:
				if ((int)fieldToScan[y][x] > 48 && (int)fieldToScan[y][x] < 53) {
					if ((int)fieldToScan[y][x] == 49) {
						moveDir = 1;
						posy--;
					}
					else if ((int)fieldToScan[y][x] == 50) {
						moveDir = 2;
						posy++;
					}
					else if ((int)fieldToScan[y][x] == 51) {
						moveDir = 3;
						posx--;
					}

					else if ((int)fieldToScan[y][x] == 52) {
						moveDir = 4;
						posx++;
					}

					break;
				}
				else if ((int)fieldToScan[y][x] > 65 && (int)fieldToScan[y][x] < 91) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x]--;
					posy--;
					break;
				}
				else if ((int)fieldToScan[y][x] > 97 && (int)fieldToScan[y][x] < 123) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x]--;
					posy--;
					break;
				}
				else if ((int)fieldToScan[y][x] == 65) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x] = '.';
					posy--;
					break;
				}
				else if ((int)fieldToScan[y][x] == 97) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x] = ',';
					posy--;
					break;
				}
				else if (fieldToScan[y][x] == '.') {
					deleteFromTail();
					if (lengthOfCaterpillar == 0)
						break;
					posy--;
					break;
				}
				else if (fieldToScan[y][x] == ',') {
					deleteFromHead();
					if (lengthOfCaterpillar == 0)
						break;
					posy--;;
					break;
				}
				else posy--;;
				break;
			case 2:
				if ((int)fieldToScan[y][x] > 48 && (int)fieldToScan[y][x] < 53) {
					if ((int)fieldToScan[y][x] == 49) {
						moveDir = 1;
						posy--;
					}
					else if ((int)fieldToScan[y][x] == 50) {
						moveDir = 2;
						posy++;
					}
					else if ((int)fieldToScan[y][x] == 51) {
						moveDir = 3;
						posx--;
					}

					else if ((int)fieldToScan[y][x] == 52) {
						moveDir = 4;
						posx++;
					}

					break;
				}
				else if ((int)fieldToScan[y][x] > 65 && (int)fieldToScan[y][x] < 91) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x]--;
					posy++;
					break;
				}
				else if ((int)fieldToScan[y][x] > 97 && (int)fieldToScan[y][x] < 123) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x]--;
					posy++;
					break;
				}
				else if ((int)fieldToScan[y][x] == 65) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x] = '.';
					posy++;
					break;
				}
				else if ((int)fieldToScan[y][x] == 97) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x] = ',';
					posy++;
					break;
				}
				else if (fieldToScan[y][x] == '.') {
					deleteFromTail();
					if (lengthOfCaterpillar == 0)
						break;
					posy++;
					break;
				}
				else if (fieldToScan[y][x] == ',') {
					deleteFromHead();
					if (lengthOfCaterpillar == 0)
						break;
					posy++;
					break;
				}
				else posy++;
				break;
			case 3:
				if ((int)fieldToScan[y][x] > 48 && (int)fieldToScan[y][x] < 53) {
					if ((int)fieldToScan[y][x] == 49) {
						moveDir = 1;
						posy--;
					}
					else if ((int)fieldToScan[y][x] == 50) {
						moveDir = 2;
						posy++;
					}
					else if ((int)fieldToScan[y][x] == 51) {
						moveDir = 3;
						posx--;
					}

					else if ((int)fieldToScan[y][x] == 52) {
						moveDir = 4;
						posx++;
					}

					break;
				}
				else if ((int)fieldToScan[y][x] > 65 && (int)fieldToScan[y][x] < 91) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x]--;
					posx--;
					break;
				}
				else if ((int)fieldToScan[y][x] > 97 && (int)fieldToScan[y][x] < 123) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x]--;
					posx--;
					break;
				}
				else if ((int)fieldToScan[y][x] == 65) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x] = '.';
					posx--;
					break;
				}
				else if ((int)fieldToScan[y][x] == 97) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x] = ',';
					posx--;
					break;
				}
				else if (fieldToScan[y][x] == '.') {
					deleteFromTail();
					if (lengthOfCaterpillar == 0)
						break;
					posx--;
					break;
				}
				else if (fieldToScan[y][x] == ',') {
					deleteFromHead();
					if (lengthOfCaterpillar == 0)
						break;
					posx--;
					break;
				}
				else posx--;
				break;
			case 4:
				if ((int)fieldToScan[y][x] > 48 && (int)fieldToScan[y][x] < 53) {
					if ((int)fieldToScan[y][x] == 49) {
						moveDir = 1;
						posy--;
					}
					else if ((int)fieldToScan[y][x] == 50) {
						moveDir = 2;
						posy++;
					}
					else if ((int)fieldToScan[y][x] == 51) {
						moveDir = 3;
						posx--;
					}

					else if ((int)fieldToScan[y][x] == 52) {
						moveDir = 4;
						posx++;
					}

					break;
				}
				else if ((int)fieldToScan[y][x] > 65 && (int)fieldToScan[y][x] < 91) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x]--;
					posx++;
					break;
				}
				else if ((int)fieldToScan[y][x] > 97 && (int)fieldToScan[y][x] < 123) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x]--;
					posx++;
					break;
				}
				else if ((int)fieldToScan[y][x] == 65) {
					addToTheEnd(fieldToScan[y][x] + 32);
					fieldToScan[y][x] = '.';
					posx++;
					break;
				}
				else if ((int)fieldToScan[y][x] == 97) {
					addAtBeggining(fieldToScan[y][x]);
					fieldToScan[y][x] = ',';
					posx++;
					break;
				}
				else if (fieldToScan[y][x] == '.') {
					deleteFromTail();
					if (lengthOfCaterpillar == 0)
						break;
					posx++;
					break;
				}
				else if (fieldToScan[y][x] == ',') {
					deleteFromHead();
					if (lengthOfCaterpillar == 0)
						break;
					posx++;
					break;
				}
				else posx++;
				break;
			}
			if (lengthOfCaterpillar == 0)
				break;

		}
		posx = x + 1;
		posy = y + 1;
		print();
	}

	~Caterpillar() {
		while (lengthOfCaterpillar) { //deallocating memory
			deleteFromTail();
		}
	}
};

int main() {

	int width, height, movements;
	int posX, posY, length; // starting position and length
	scanf("%d", &width);
	scanf("%d", &height);
	scanf("%d", &movements);
	scanf("%d", &posX);
	scanf("%d", &posY);
	scanf("%d", &length);
	char *ptr = (char*)malloc(sizeof(char)*(length + 1)); // starting length of caterpillar
    if(length)
	   scanf("%s", ptr);
	ptr[length] = '\0';
	Caterpillar cat(ptr, posX, posY); //creation of caterpillar
	char **field = (char**)malloc(sizeof(char*)*height); //allocation of the gameboard
	for (int i = 0; i < height; i++) {
		field[i] = (char*)malloc(sizeof(char)*width);
		scanf("%s", field[i]);
	}
	cat.scanner(field, width, height, movements); //simulation loop

	for (int i = 0; i < height; i++) { // replacing wastes with @
		for (int j = 0; j < width; j++)
			if (field[i][j] == '.' || field[i][j] == ',')
				field[i][j] = '@';
		printf("%s\n", field[i]);
	}

	
	free(field);
	return 0;
}
