// #include <stdio.h>
// int main()
// {
//     int i, j, x, y, arr[100], n1, n2, Op;
//     printf("Number of  Element to be Stored in Array ? ");
//     scanf("%d", &y);
//     printf("Enter %d Array Elements: ", y);
//     for (i = 0; i < y; i++)
//         scanf("%d", &arr[i]);

//     printf("Enter Option : \n 1.To insert  in Array \n 2.To delete in Array \n");
//     scanf("%d", &Op);

//     switch (Op)
//     {
//     case 1:
//         // printf("\nAt what position ? ");
//         printf("\nEnter Element to Insert: ");
//         scanf("%d", &j);
//         printf("\nAt what position ? ");
//         scanf("%d", &x);
//         for (i = y; i >= x; i--)
//             arr[i] = arr[i - 1];
//         arr[i] = j;
//         y++;
//         break;

//     case 2:
//         printf("\nEnter Element to Insert: ");
//         break;

//     default:
//         printf("Error! Option is not correct");
//     }

//     // printf("\nThe New Array is:\n");
//     // for (i = 0; i < y; i++)
//     //     printf("%d  ", arr[i]);
//     return 0;
// }

    printf("\nAt what position ? ");
    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &position);

    if (position >= n + 1)
        printf("Deletion not possible.\n");
    else
    {
        for (int c = position - 1; c < n - 1; c++)
            arr[c] = arr[c + 1];

        printf("Resultant array:\n");

        for (int c = 0; c < n - 1; c++)
            printf("%d\n", arr[c]);
    }








    int array[100], position, c, n;
    
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    
    printf("Enter %d elements\n", n);
    
    for ( c = 0 ; c < n ; c++ )
    scanf("%d", &array[c]);
    
    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &position);
    
    if ( position >= n+1 )    
    printf("Deletion not possible.\n");
    
    else
    {    
        for ( c = position - 1 ; c < n - 1 ; c++ ) 
        array[c] = array[c+1];        
        
        printf("Resultant array is\n");
        
        for( c = 0 ; c < n - 1 ; c++ )        
        printf("%d\n", array[c]);        
    }    