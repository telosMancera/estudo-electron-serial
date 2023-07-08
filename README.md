# estudo-electron-serial

Estudo sobre comunicação serial utilizando framework Electron.

## Contexto

Este estudo está sendo feito para realização de um de meus projetos que estou envolvido atualmente. Neste projeto, um equipamento possui uma placa microcontrolada, no qual o firmware estou desenvolvendo, e esta placa se comunica através de uma comunicação serial com uma aplicação rodando em ambiente Windows, que será também desenvolvida.

Além disso, estou aprendendo o framework Electron, o qual foi o frmamework que eu acabei escolhendo para desenvolver a aplicação para desktop.

## Repositório

O repositório contém o código fonte para as duas aplicações, quanto a do desktop, quanto o firmware da placa.

## Um pouco sobre cada aplicação

### Desktop

A aplicação no desktop será feita utilizando-se o framework Electron.

A aplicação deve ficar ouvindo a placa, enquanto replica na tela os valores lidos.

Um botão deve ser adicinado de tal forma a testar a comunicação na direção Desktop > Placa.

O código da aplicação foi baseado nos seguintes guias:

- https://www.electronjs.org/docs/latest/tutorial/devices#web-serial-api
- https://developer.chrome.com/articles/serial/

### Placa

O firmware da placa será feito no projeto para um uC da família PIC32MM. Porém, para teste será utilizado uma Arduino Uno.

A placa deve ficar enviando dados de forma serial para o Desktop.

Eventualmente dados chegarão do Desktop e a placa deve fazer algo com este dado.
