// Dynamically create the family tree from JSON data
const familyTreeDiv = document.getElementById('familyTree');

// Function to create the tree structure recursively
function createTreeNode(member) {
    const li = document.createElement('li');
    
    // Create the person's box
    const span = document.createElement('span');
    span.textContent = member.name;
    span.classList.add('person-box'); // Add person-box class for fixed size
    
    li.appendChild(span);
    
    if (member.children.length > 0) {
        // Create a list to hold the children nodes
        const ul = document.createElement('ul');
        
        // Set display to flex for horizontal alignment
        ul.style.display = 'flex';
        ul.style.justifyContent = 'center';

        // Recursively create children nodes
        member.children.forEach(child => {
            ul.appendChild(createTreeNode(child));
        });

        li.appendChild(ul);

        // Create a collapse button (-) and add it to the node
        const collapseBtn = document.createElement('button');
        collapseBtn.textContent = '+'; // Start with expand symbol
        collapseBtn.classList.add('collapse'); // Small button next to the person box
        li.appendChild(collapseBtn);

        // Hide children initially
        ul.style.display = 'none';

        // Toggle children visibility on click
        collapseBtn.addEventListener('click', () => {
            if (ul.style.display === 'none') {
                ul.style.display = 'flex'; // Show children
                collapseBtn.textContent = '−'; // Change to collapse symbol
            } else {
                ul.style.display = 'none'; // Hide children
                collapseBtn.textContent = '+'; // Change to expand symbol
            }
        });
    }

    return li;
}

// Function to render the tree
function renderTree(data) {
    const ul = document.createElement('ul');
    ul.classList.add('tree');
    ul.appendChild(createTreeNode(data));
    familyTreeDiv.appendChild(ul);
}

// Render the family tree using the provided data
renderTree(familyData);
