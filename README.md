
# 🌐 Guia Simples: Criando um Servidor HTTP em C

Bem-vindo! Este guia vai te mostrar, passo a passo, como esse projeto funciona e como você pode rodar um servidor HTTP básico em C. Vamos nessa? 🚀

---

## 📦 Sobre o Projeto

Este é um servidor HTTP **feito do zero em C**. Ele escuta conexões na porta 3490 e responde com uma página HTML simples. Ideal pra quem quer entender como a web funciona por trás dos panos.

---

## 🧰 O que você vai precisar

Antes de começar, verifique se tem o seguinte:

- ✅ Um compilador C (como o `gcc`)
- ✅ Um terminal (Linux ou WSL no Windows)
- ✅ Vontade de aprender! 😄

---

## 🛠️ Como Compilar

Abra o terminal na pasta do projeto e digite:

```bash
gcc server.c -o server
```

Isso vai compilar o código e gerar um executável chamado `server`.

---

## 🚀 Como Rodar

Ainda no terminal, execute:

```bash
./server
```

O servidor vai iniciar e começar a escutar conexões na porta **3490**.

---

## 🌍 Como Acessar

Abra seu navegador e digite:

```
http://localhost:3490
```

Você verá uma página HTML simples, enviada pelo seu próprio servidor!

---

## 🧠 O que acontece por trás?

Vamos explicar de forma simples o que o código faz:

1. 🧪 **Cria um socket** – como se fosse um telefone pronto para receber ligações.
2. 🪛 **Configura opções** – define que o socket pode ser reutilizado.
3. 🧱 **Associa o socket a uma porta (3490)** – conecta o telefone a uma linha.
4. 👂 **Escuta conexões** – espera alguém ligar.
5. 🤝 **Aceita uma conexão** – atende a ligação.
6. 📩 **Lê os dados** – ouve o que a pessoa do outro lado falou.
7. ✉️ **Envia uma resposta** – devolve uma página HTML como resposta.
8. 🔁 **Fecha a conexão e espera a próxima**.

---

## 💡 Curiosidade

Esse projeto é inspirado no famoso guia de redes do Beej:
👉 [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/split-wide/index.html)

---

## 🧪 Testando com `curl`

Se quiser ver a resposta direto no terminal, use:

```bash
curl http://localhost:3490
```

---

## 🧹 Finalizando

Para parar o servidor, pressione `Ctrl + C`.


Feito com ❤ para quem quer aprender mais sobre C e redes!
