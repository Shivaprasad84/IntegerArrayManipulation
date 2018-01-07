#include <stdio.h>
#include <stdlib.h>

int main()
{
	int f_choice, s_choice, t_choice, a[100], n, k, pos, i, j, temp, key, KeyPos, deleted, count = 0, loop = 0;
	while (1)
	{
		// Choose option list A
		if (loop == 0)
			printf("1.Input an array\n");
		else
			printf("1.Input a new array\n");

		printf("2.Exit\n");
		if (loop > 0)
		{
			printf("3.Manipulate previous array\n");
			printf("4.View the previous array\n");
		}
		scanf("%d", &f_choice);
		if (f_choice == 1)
		{
			// storing an array of given size(n) in a
			system("clear");
			printf("Enter the size of the array\n");
			scanf("%d", &n);
			printf("Enter the %d array elements\n", n);
			for (i = 0; i < n; i++)
			{
				scanf("%d", &a[i]);
			}

there:
			//Choose option list B  (New array Manipulation)
			printf("\n1.Insert an element into the array\n");
			printf("2.Delete an element from the array\n");
			printf("3.Sort the array in ascending order\n");
			printf("4.Sort the array in descending order\n");
			printf("5.Search for an element in the array\n");
			printf("6.Reverse the order of the array\n");
			printf("7.Exit\n");
			scanf("%d", &s_choice);
			if (s_choice == 1)
			{

				// Insert an element into the array
ins:
				printf("Enter the element to be inserted\n");
				scanf("%d", &k);
miss:
				printf("Enter the position where %d is to be inserted\n", k);
				scanf("%d", &pos);
				if (pos <= 0 || pos - 1 > n)
				{
					printf("Invalid position\n");
					getchar();
					getchar();
					system("clear");
					goto miss;
				}
				pos = pos - 1;
				for (i = n; i > pos; i--)
				{
					a[i] = a[i - 1];
				}
				a[pos] = k;
				printf("The array with %d inserted at position %d is\n", k, pos + 1);
				for (i = 0; i <= n; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n");
				n = n + 1;
				getchar();
				goto bottom;
			}
			else if (s_choice == 2 && n > 0)
			{

				// Delete an element from the array
del:
				printf("Enter the position of the number to be deleted\n");
				scanf("%d", &pos);
				if (pos <= 0 || pos - 1 > n)
				{
					printf("Invalid position\n");
					getchar();
					getchar();
					system("clear");
					goto del;
				}
				pos = pos - 1;
				deleted = a[pos];
				for (i = pos; i < n - 1; i++)
				{
					a[i] = a[i + 1];
				}
				printf("The array with the element %d deleted from position %d deleted is\n", deleted, pos + 1);
				for (i = 0; i < n - 1; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n");
				n = n - 1;
				if (n == 0)
				{
					printf("There are no more elements in the array dont choose delete previous array\n");
					getchar();
					goto bottom;
				}
				getchar();
				goto bottom;
			}

			else if (s_choice == 3)
			{

				// Sort array in ascending order (bubble sort)
sortA:
				for (j = 0; j < n - 1; j++)
				{
					for (i = 0; i < n - 1; i++)
					{
						if (a[i] > a[i + 1])
						{
							temp = a[i];
							a[i] = a[i + 1];
							a[i + 1] = temp;
						}
					}
				}

				printf("The array sorted in ascending order is\n");
				for (i = 0; i < n; i++)
				{
					printf("%d ", a[i]);
				}

				getchar();
				goto bottom;
			}

			else if (s_choice == 4)
			{

				// Sort array in descending order (bubble sort)
sortD:
				for (j = 0; j < n - 1; j++)
				{
					for (i = 0; i < n - 1; i++)
					{
						if (a[i] < a[i + 1])
						{
							temp = a[i];
							a[i] = a[i + 1];
							a[i + 1] = temp;
						}
					}
				}

				printf("The array sorted in descending order is\n");
				for (i = 0; i < n; i++)
				{
					printf("%d ", a[i]);
				}

				getchar();
				goto bottom;
			}

			else if (s_choice == 5)
			{

				// Search for an element in the array (Linear search)
search:
				printf("Enter the element to be searched\n");
				scanf("%d", &key);
				system ("clear");
				for (i = 0; i < n; i++)
				{
					if (key == a[i])
					{
						KeyPos = i + 1;
						if (count == 0)
							printf("\n%d is present at position %d in the array\n\n", key, KeyPos);
						else
							printf("%d is also present at position %d in the array\n\n", key, KeyPos);
						count++;
						for (j = 0; j < n; j++)
						{
							printf("%d ", a[j]);
						}

						printf("\n\n");

					}
				}

				if (count == 0)
				{
					printf("%d is not present in the array\n", key);
					getchar();
					goto bottom;
				}
				else
				{
					if (count > 1)
					{
						printf("%d is present %d times in the array\n", key, count);
						getchar();
						goto bottom;
					}
					else
					{
						getchar();
						goto bottom;
					}
				}
			}

			else if (s_choice == 6)
			{

				// Reverse the order of the array
reverse:
				for (i = 0, j = n - 1; i < n - 1 && j > i; i++, j--)
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}

				printf("The reversed array is\n");
				for (i = 0; i < n; i++)
				{
					printf("%d ", a[i]);
				}

				getchar();
				goto bottom;
			}


			else if (s_choice == 7)
			{
				exit(0);
			}
			else
			{
				printf("Invalid choice\n");
				getchar();
				getchar();
				system("clear");
				goto there;
			}
		}
		else if (f_choice == 2)
		{
			exit(0);
		}

		else if (f_choice == 3 && loop > 0)
		{

			// Control Enters here after selection of choice 3 in List A (Manipulation of the previous array)
top:
			printf("1.Insert an element into the array\n");
			printf("2.Delete an element from the array\n");
			printf("3.Sort the array in ascending order\n");
			printf("4.Sort the array in descending order\n");
			printf("5.Search for an element in the array\n");
			printf("6.Reverse the order of the array\n");
			printf("7.Exit\n");
			scanf("%d", &t_choice);
			if (t_choice == 1)
			{
				goto ins;
			}
			else if (t_choice == 2 && n > 0)
			{
				goto del;
			}
			else if (t_choice == 3)
			{
				goto sortA;
			}
			else if (t_choice == 4)
			{
				goto sortD;
			}
			else if (t_choice == 5)
			{
				goto search;
			}
			else if (t_choice == 6)
			{
				goto reverse;
			}
			else if (t_choice == 7)
			{
				exit(0);
			}
			else
			{
				printf("Invalid choice\n");
				getchar();
				getchar();
				system("clear");
				goto top;
			}
		}
		else if (f_choice == 4 && loop > 0)
		{
			// View the array
			for (i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\nThere are %d elements in the array", n);
			getchar();
			goto bottom;

		}
		else
		{
			printf("Invalid choice\n");
			getchar();
			goto bypass;
		}

bottom:
		loop++;
		count = 0;
bypass:
		getchar();
		system("clear");
	}

	getchar();
	return 0;
}


