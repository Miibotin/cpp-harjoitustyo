Jaan tänne vaan mun task-komennot...

```
{
      "type": "shell",
      "label": "Compile",
      "command": "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
      "args": [
        "-c",
        "${workspaceFolder}/*.cpp*",
        "|",
        "g++",
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
      "problemMatcher": []
    },
    {
      "type": "shell",
      "label": "Clean",
      "command": "rm",
      "args": [
        "-Force",
        "${workspaceFolder}/*.o*"
      ],
      "problemMatcher": []
    }
```