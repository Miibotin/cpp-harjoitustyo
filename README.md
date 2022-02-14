### HUOM. TOTEUTETTU VISUAL STUDIO CODE:N AVULLA, JOTEN SLN-TIEDOSTOA VISUAL STUDIO-PROJEKTIA VARTEN EI OLE SAATAVILLA

vscoden task-komennot...

```
{
      "type": "shell",
      "label": "Compile",
      "command": "URL FOR COMPILER HERE",
      "args": [
        "-c",
        "${workspaceFolder}/*.cpp*",
        "|",
        "g++",
        "-o",
        "Main.exe",
        "${workspaceFolder}/*.o*"
      ],
      "presentation": {
        "echo": true,
        "reveal": "always",
        "focus": false,
        "panel": "shared",
        "showReuseMessage": true,
        "clear": false
      },
      "problemMatcher": [
        "$gcc"
      ]
    },
    {
      "type": "shell",
      "label": "Clean",
      "command": "rm",
      "args": [
        "-Force",
        "${workspaceFolder}/*.o*"
      ],
      "problemMatcher": [
        "$gcc"
      ]
    }
```
