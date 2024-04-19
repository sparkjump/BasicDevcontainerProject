FROM debian:bookworm-slim

# Set the default shell to bash
SHELL ["/bin/bash", "-c"]

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

#########################################
# Create the development user
RUN groupadd --gid ${USER_GID} ${USERNAME} && \
    useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} && \
    apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -yy --no-install-recommends sudo && \
    apt-get clean && rm -rf /var/lib/apt/lists/* && \
    echo "${USERNAME} ALL=(root) NOPASSWD:ALL" >/etc/sudoers.d/${USERNAME} && \
    chmod 0440 /etc/sudoers.d/${USERNAME}

# Install programs
RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive \
    apt-get install -y --no-install-recommends \
    # general packages and utility functions
    build-essential ninja-build ccache \
    cmake \
    git \
    ca-certificates \
    curl \
    fzf \
    ripgrep \
    bat \
    # Cleanup
    && apt-get clean && rm -rf /var/lib/apt/lists/*

#########################################
# Install up-to-date clang tools
RUN echo "deb https://apt.llvm.org/bookworm llvm-toolchain-bookworm-16 main" \
    > /etc/apt/sources.list.d/llvm.list && \
    curl -q -L -o /etc/apt/trusted.gpg.d/llvm.asc \
    https://apt.llvm.org/llvm-snapshot.gpg.key && \
    apt-get -qq update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -qqy -t llvm-toolchain-bookworm-16 clang-16 clang-format-16 clang-tidy-16 && \
    ln -sf clang-format-16 /usr/bin/clang-format && \
    ln -sf clang-tidy-16 /usr/bin/clang-tidy && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

#########################################
# Install docker using the get.docker script. This will put out some warnings about WSL and sleep for 20 seconds
RUN curl -fsSL https://get.docker.com | sh && \
    usermod -a -G docker ${USERNAME}

# Switch to the non-root user when the container starts
WORKDIR /home/${USERNAME}
USER ${USERNAME}

# Copy configuration files
COPY --chown=${USER_UID}:${USER_GID} .bashrc .profile .gitconfig /home/${USERNAME}/

# Start bash in login mode as the default command
CMD ["/bin/bash", "-l"]
