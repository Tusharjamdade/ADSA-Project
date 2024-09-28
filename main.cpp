#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>

using namespace std;

// Linked list node
struct node {
    char song[100];
    struct node *next;
    struct node *prev;
} *top, *temp, *top1;

// Binary Search Tree (BST) node
struct TreeNode {
    char song[100];
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

// Graph node
struct GraphNode {
    char song[100];
    list<GraphNode*> adjacent;
};

// Function to save the song to a file
void tofile(char a[]) {
    fstream f1;
    f1.open("playlist.txt", ios::out | ios::app);
    f1 << a << endl;
    f1.close();
}

// Function to add a new node to the playlist (linked list)
void add_node(struct node* first) {
    char a[100];
    while (first->next != NULL) {
        first = first->next;
    }
    first->next = (struct node*)malloc(sizeof(struct node));
    first->next->prev = first;
    first = first->next;
    cout << "\nEnter Song name: ";
    scanf("%s", a);
    strcpy(first->song, a);
    tofile(a);
    first->next = NULL;
}

// Function to print the linked list (playlist)
void printlist(struct node* first) {
    cout << "\nPlaylist:";
    while (first != NULL) {
        cout << first->song << endl;
        first = first->next;
    }
}

// Function to count the total number of songs in the playlist
void count_nodes(struct node* first) {
    int i = 0;
    while (first != NULL) {
        first = first->next;
        i++;
    }
    cout << "\nTotal songs: " << i << endl;
}

// Binary Search Tree (BST) functions
TreeNode* create_tree(char* song) {
    TreeNode* newNode = new TreeNode();
    strcpy(newNode->song, song);
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void insert_song_into_tree(TreeNode* root, char* song) {
    if (root == NULL) return;

    TreeNode* newNode = create_tree(song);
    TreeNode* parent = NULL;
    TreeNode* current = root;

    while (current != NULL) {
        parent = current;
        if (strcmp(song, current->song) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (strcmp(song, parent->song) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void traverse_tree(TreeNode* root) {
    if (root == NULL) return;
    traverse_tree(root->left);
    cout << root->song << endl;
    traverse_tree(root->right);
}

// Graph functions
GraphNode* create_graph_node(char* song) {
    GraphNode* newNode = new GraphNode();
    strcpy(newNode->song, song);
    return newNode;
}

void add_edge(GraphNode* node1, GraphNode* node2) {
    node1->adjacent.push_back(node2);
    node2->adjacent.push_back(node1);
}

list<char*> find_connected_songs(GraphNode* song_node) {
    list<char*> connected_songs;
    for (auto& adj : song_node->adjacent) {
        connected_songs.push_back(adj->song);
    }
    return connected_songs;
}

// Integrated functions
void add_song_to_playlist_and_tree(TreeNode* root, struct node* first, char* song) {
    add_node(first);
    insert_song_into_tree(root, song);
}

list<char*> recommend_similar_songs(GraphNode* song_node) {
    return find_connected_songs(song_node);
}

// Main function to demonstrate usage
int main() {
    int choice;
    char song[100];

    // Linked list playlist
    struct node* playlist = (struct node*)malloc(sizeof(struct node));
    playlist->next = NULL;
    strcpy(playlist->song, "Root Song"); // Placeholder

    // Binary Search Tree (BST) for songs
    TreeNode* tree_root = create_tree("Root Song");

    // Graph structure for song recommendations
    GraphNode* graph_root = create_graph_node("Root Song");

    do {
        cout << "\n1. Add New Song to Playlist and Tree\n2. Display Playlist\n3. Display Sorted Songs (Tree)\n4. Recommend Similar Songs (Graph)\n5. Total Songs\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                cin >> song;
                add_song_to_playlist_and_tree(tree_root, playlist, song);

                // Optional: Connect to other songs in the graph for recommendation
                add_edge(graph_root, create_graph_node(song));
                break;

            case 2:
                printlist(playlist);
                break;

            case 3:
                cout << "Sorted Songs (Tree):\n";
                traverse_tree(tree_root);
                break;

            case 4: {
                list<char*> recommendations = recommend_similar_songs(graph_root);
                cout << "Recommended Songs:\n";
                for (const auto& rec_song : recommendations) {
                    cout << rec_song << endl;
                }
                break;
            }

            case 5:
                count_nodes(playlist);
                break;

            case 6:
                exit(0);
                break;
        }
    } while (choice != 6);

    return 0;
}

