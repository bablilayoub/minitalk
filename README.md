# Minitalk

## Summary

The Minitalk project is a small data exchange program using UNIX signals. The program consists of a client and a server, communicating through signals (SIGUSR1 and SIGUSR2). The server is responsible for receiving strings from multiple clients and displaying them quickly. The project includes both mandatory and bonus parts.

**Version:** 3

## Table of Contents

- [Foreword](#foreword)
- [Common Instructions](#common-instructions)
- [Project Instructions](#project-instructions)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Submission and Peer-evaluation](#submission-and-peer-evaluation)

## Foreword

The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily liquid with an intense grassy-green odor of freshly cut green grass and leaves. It is produced in small amounts by most plants and acts as an attractant to many predatory insects. cis-3-Hexen-1-ol is a crucial aroma compound used in fruit and vegetable flavors and perfumes, with a yearly production of about 30 tonnes.

## Common Instructions

- Project must be written in C.
- Follow the Norm guidelines.
- Functions should not quit unexpectedly.
- Free heap allocated memory properly; no memory leaks.
- Include a Makefile with required flags.
- Makefile must have rules: $(NAME), all, clean, fclean, re.
- For bonuses, include a rule bonus in the Makefile.
- If using libft, copy its sources to a libft folder.
- Encouraged to create test programs.
- Submit work to assigned Git repository.

## Project Instructions

- Executables: client and server.
- Include a Makefile that does not relink.
- Use libft if allowed.
- Thorough error handling; program should not quit unexpectedly.
- No memory leaks allowed.
- One global variable per program, justified.
- Allowed functions include: write, ft_printf (or equivalent), signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit.

## Mandatory Part

Create a communication program with a client and a server:

- Server must be started first and print its PID.
- Client takes server PID and string to send as parameters.
- Client sends the string to the server.
- Server prints the received string quickly.
- Server can handle strings from multiple clients without restarting.
- Communication between client and server only using UNIX signals (SIGUSR1 and SIGUSR2).

## Bonus Part

- Server acknowledges every received message by sending a signal back to the client.
- Unicode characters support.

**Note:** The bonus part will only be assessed if the mandatory part is perfect.

## Submission and Peer-evaluation

Submit the assignment in the Git repository. Only the work inside the repository will be evaluated during the defense. Double-check file names for correctness.
